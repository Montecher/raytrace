#include "Cam.h"
#include "constants.h"
#include "color.h"
#include "endian.h"
#include <cmath>
#include <cstdlib>

static inline double clamp(double v, double min=0., double max=1.) {
    if(v<min) return min;
    if(v>max) return max;
    return v;
}
static inline int toInt(double v) {
    return (int) (pow(clamp(v, 0., 1.), 1/2.2) * 255. + .5);
}

Cam::Cam() {
    this->orig = Vec3::O;
    this->dir = Vec3::X;
    this->right = Vec3::Y;
    this->up = Vec3::Z;

    this->width = 1;
    this->height = 1;
}

Cam::Cam(Vec3 orig, Vec3 dir, const Vec3& right, double width, double height) {
    this->orig = orig;
    this->dir = dir;
    this->right = right.normal();
    this->up = (dir ^ right).normal();

    this->width = width;
    this->height = height;
}

bool Cam::get_pixel(Object* scene, int x, int y, int w, int h, double* t, Vec3* impact, Vec3* normal, const Material** obj) const {
    Ray ray = this->ray(x, y, w, h);
    bool hit = false;
    *t = MAX_DIST;

    hit = ray.intersect(scene, t, impact, normal);
    if(hit) {
        *obj = scene->get_intersecting(*impact);
    }

    return hit;
}

void Cam::setPos(const Vec3& pos) {
    this->orig = pos;
}
void Cam::setPointing(const Vec3& pointing) {
    this->dir = (pointing - this->orig).normal();
    this->right = -(this->dir ^ Vec3::Z).normal();
    this->up = -(this->right ^ this->dir).normal();
}

#define pi std::acos(-1)
static rgb_color shade(Object* scene, Vec3 normal, Vec3 ray, Vec3 impact) {
    static Vec3 lightsource = Vec3::Z*4 -Vec3::X*2;
    Ray rayToLight = Ray(lightsource, impact-lightsource);
    double distToLight = MAX_DIST;
    Vec3 normalToLight;
    Vec3 impactToLight;
    rayToLight.intersect(scene, &distToLight, &impactToLight, &normalToLight);
    double angleToLight = (lightsource-impact).angle_to(normal);
    distToLight = (impactToLight-impact).hypot();

    double angle = ray.angle_to(normal);
    hsv_color hsv = {
        h: 45 - angle * 180 / pi / 2,
        s: clamp(0., 1., angleToLight / pi),
        v: clamp(0., 1., 5 / (distToLight*distToLight))
    };
    return hsv_to_rgb(hsv);
}

Image Cam::render_shaded(Object* scene, int w, int h) const {
    Image img = Image(w, h);
#pragma omp parallel for
    for(int y = 0; y < h; y++) {
        for(int x = 0; x < w; x++) {
            double t;
            Vec3 impact, normal;
            const Material* obj;
            bool hit = get_pixel(scene, x, y, w, h, &t, &impact, &normal, &obj);

            if (hit) {
                rgb_color rgb = shade(scene, normal, orig-impact, impact);
                img.pixel(x, y, rgb);
            } else {
                img.pixel(x, y, rgb_black);
            }
        }
    }
    return img;
}


// shamelessly stolen from https://www.kevinbeason.com/smallpt/
static Vec3 radiance(const Ray &r, Object* scene, int depth, unsigned short *Xi) {
    double t = MAX_DIST;
    Vec3 impact, normal;

    // no hit -> black
    if(!r.intersect(scene, &t, &impact, &normal)) {
        return Vec3::O;
    }

    const Material* material = scene->get_intersecting(impact);

    Vec3 x = impact;
    Vec3 n = normal;
    Vec3 nl = normal; // or -normal, I don't really understand it
    Vec3 f = material->color();

    // max reflection
    if(++depth>5) {
        return material->color();

        // the following seemed to just go on forever, so I commented it out
        /*
        double p = std::max(std::max(f.get_x(), f.get_y()), f.get_z());
        if (erand48(Xi)<p) f=f*(1/p);
        else return material->color(); //R.R.
        */
    }

    if(material->reflection() == DIFFUSE) {
        // diffusion
        double r1 = 2*M_PI*erand48(Xi);
        double r2=erand48(Xi);
        double r2s=sqrt(r2);
        Vec3 w = nl;
        Vec3 u = ( (fabs(w.get_x())>.1 ? Vec3::Y : Vec3::X) ^ w ).normal();
        Vec3 v = w^u;
        Vec3 d = (u*cos(r1)*r2s + v*sin(r1)*r2s + w*sqrt(1-r2)).normal();
        return  material->emission() + f.mult(radiance(Ray(x, d), scene, depth, Xi));
    } else if (material->reflection() == REFLECTIVE) {
        // reflection
        return material->emission() + f.mult(radiance(Ray(x, r.get_dir()-n*2*(n*r.get_dir())), scene, depth, Xi));
    } else {
        // refraction

        // until I find a clean way to do this, it's just not there
        // I'll need to find a way to make a ray go through an object and detect the end of that
        // pretty sure this isn't possible when working with unions and signed distance field
        return Vec3::O;

        // do something about this at some point
        /*
        // refraction
        Ray reflRay(x, r.get_dir()-n*2*n*r.get_dir()));     // Ideal dielectric REFRACTION
        bool into = n*nl>0;                // Ray from outside going in?
        double nc=1, nt=1.5, nnt=into?nc/nt:nt/nc, ddn=r.d.dot(nl), cos2t;
        if ((cos2t=1-nnt*nnt*(1-ddn*ddn))<0)    // Total internal reflection
        return obj.e + f.mult(radiance(reflRay,depth,Xi));
        Vec tdir = (r.d*nnt - n*((into?1:-1)*(ddn*nnt+sqrt(cos2t)))).norm();
        double a=nt-nc, b=nt+nc, R0=a*a/(b*b), c = 1-(into?-ddn:tdir.dot(n));
        double Re=R0+(1-R0)*c*c*c*c*c,Tr=1-Re,P=.25+.5*Re,RP=Re/P,TP=Tr/(1-P);
        return obj.e + f.mult(depth>2 ? (erand48(Xi)<P ?   // Russian roulette
        radiance(reflRay,depth,Xi)*RP:radiance(Ray(x,tdir),depth,Xi)*TP) :
        radiance(reflRay,depth,Xi)*Re+radiance(Ray(x,tdir),depth,Xi)*Tr);
        */
    }
}

Image Cam::render_realistic(Object* scene, int w, int h, int samples) const {
    Image img = Image(w, h);

#pragma omp parallel for
    // loop over pixels, use multithread on rows
    for(int y=0; y<h; y++) {
        for(unsigned short x=0; x<w; x++) {

            unsigned short Xi[3] = {0, 0, (unsigned short) (y*y*y)};
            Vec3 r = Vec3::O;

            // loop over subpixels
            for(int sy=0; sy<2; sy++) {
                for(int sx=0; sx<2; sx++) {

                    Vec3 sc = Vec3::O;

                    // loop over samples
                    for(int s=0; s<samples; s++) {
                        Ray ray = this->ray(x, y, w, h);
                        sc = sc + radiance(ray, scene, 0, Xi) * 1./samples;

                        // maybe do something about this at some point
                        /*
                        double r1 = 2*erand48(Xi);
                        double dx = r1<1 ? sqrt(r1)-1: 1-sqrt(2-r1);
                        double r2 = 2*erand48(Xi);
                        double dy = r2<1 ? sqrt(r2)-1: 1-sqrt(2-r2);
                        Vec d = cx*( ( (sx+.5 + dx)/2 + x)/w - .5) + cy*( ( (sy+.5 + dy)/2 + y)/h - .5) + cam.d;
                        r = r + radiance(Ray(cam.o+d*140,d.norm()),0,Xi)*(1./samps);
                        */
                    }

                    // merge subpixel value
                    r = r + Vec3(clamp(sc.get_x()),clamp(sc.get_y()),clamp(sc.get_z()))*.25;
                }
            }

            // merge pixel value
            img.pixel(x, y, {(unsigned char) toInt(r.get_x()), (unsigned char) toInt(r.get_y()), (unsigned char) toInt(r.get_z())});
        }
    }

    return img;
}
