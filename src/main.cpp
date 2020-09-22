//
// Created by ara0n on 9/17/20.
//

#include <iostream>
#include "Vec3.h"

using namespace std;

int main(){
    cout << "hello world!" << endl;
    Vec3 a = Vec3();
    Vec3 b = Vec3(2, 5, 12);
    Vec3 c = Vec3(15, -3, 0);

    cout << a << endl << b << endl << c << endl << a+c << endl << b*c << endl << a.hypot() << endl;
    return 0;
}