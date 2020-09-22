//
// Created by ara0n on 9/17/20.
//

#include <iostream>
#include "Vec3.h"
#include "Sphere.h"

using namespace std;

int main(){
    cout << "hello world!" << endl;
    Vec3 a = Vec3();
    Vec3 b = Vec3(2, 5, 12);
    Vec3 c = Vec3(15, -3, 0);

    cout << a << endl << b << endl << c << endl << a+c << endl << b*c << endl << a.hypot() << endl;

    Sphere d = Sphere();
    Sphere e = Sphere(b, 21);
    Sphere f = Sphere(5, 6, 8 , 1);
    cout << d << endl << e << endl << f << endl;

    return 0;
}