#include "Light.h"

Light Light::white = Light(1, 1, 1, 1);
Light Light::black = Light(0, 0, 0, 0);

Diffusion::Diffusion() : Mat<4>() {}

Diffusion::Diffusion(double rr, double rg, double rb, double ru, double gr, double gg, double gb, double gu, double br, double bg, double bb, double bu, double ur, double ug, double ub, double uu) : Mat<4>() {
    _v[0][0] = rr;
    _v[1][0] = rg;
    _v[2][0] = rb;
    _v[3][0] = ru;

    _v[0][1] = gr;
    _v[1][1] = gg;
    _v[2][1] = gb;
    _v[3][1] = gu;

    _v[0][2] = br;
    _v[1][2] = bg;
    _v[2][2] = bb;
    _v[3][2] = bu;

    _v[0][3] = ur;
    _v[1][3] = ug;
    _v[2][3] = ub;
    _v[3][3] = uu;
}

Diffusion::Diffusion(const Light& diagonal) {
    for(int i=0; i<4; i++) _v[i][i] = diagonal.v(i);
}
