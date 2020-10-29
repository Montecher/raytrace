#ifndef __MATN_H
#define __MATN_H
#include "VecN.h"

template <unsigned int N>
class Mat {
protected:
    double _v[N][N];

public:
    Mat();
    Mat(const double[N][N]);
    Mat(const double[N*N]);

    double v(unsigned int, unsigned int) const;

    Mat<N> operator + (const Mat<N>&) const;
    Mat<N> operator - (const Mat<N>&) const;

    Mat<N> operator * (double) const;
    Mat<N> operator / (double) const;

    Mat<N> operator - () const;

    Vec<N> operator * (const Vec<N>&) const;
};

template <unsigned int N>
Mat<N>::Mat() {
    for(unsigned int i=0; i<N; i++) for(unsigned int j=0; j<N; j++) _v[i][j] = 0;
}

template <unsigned int N>
Mat<N>::Mat(const double v[N][N]) {
    for(unsigned int i=0; i<N; i++) for(unsigned int j=0; j<N; j++) _v[i][j] = v[i][j];
}

template <unsigned int N>
Mat<N>::Mat(const double v[N*N]) {
    for(unsigned int i=0; i<N; i++) for(unsigned int j=0; j<N; j++) _v[i][j] = v[i+N*j];
}

template <unsigned int N>
inline double Mat<N>::v(unsigned int i, unsigned int j) const {
    return _v[i][j];
}

template <unsigned int N>
inline Mat<N> Mat<N>::operator+(const Mat<N>& o) const {
    Mat<N> r;
    for(unsigned int i=0; i<N; i++) for(unsigned int j=0; j<N; j++) r._v[i][j] = _v[i][j] + o._v[i][j];
    return r;
}

template <unsigned int N>
inline Mat<N> Mat<N>::operator-(const Mat<N>& o) const {
    Mat<N> r;
    for(unsigned int i=0; i<N; i++) for(unsigned int j=0; j<N; j++) r._v[i][j] = _v[i][j] - o._v[i][j];
    return r;
}

template <unsigned int N>
inline Mat<N> Mat<N>::operator*(double o) const {
    Mat<N> r;
    for(unsigned int i=0; i<N; i++) for(unsigned int j=0; j<N; j++) r._v[i][j] = _v[i][j] * o;
    return r;
}

template <unsigned int N>
inline Mat<N> Mat<N>::operator/(double o) const {
    Mat<N> r;
    for(unsigned int i=0; i<N; i++) for(unsigned int j=0; j<N; j++) r._v[i][j] = _v[i][j] / o;
    return r;
}

template <unsigned int N>
inline Mat<N> Mat<N>::operator-() const {
    Mat<N> r;
    for(unsigned int i=0; i<N; i++) for(unsigned int j=0; j<N; j++) r._v[i][j] = -_v[i][j];
    return r;
}

template <unsigned int N>
inline Vec<N> Mat<N>::operator*(const Vec<N>& o) const {
    double t[N];
    for(unsigned int i=0; i<N; i++) {
        double a = 0;
        for(unsigned int j=0; j<N; j++) a += _v[i][j] * o.v(j);
        t[i] = a;
    }
    return Vec<N>(t);
}

#endif
