#ifndef __VECN_H
#define __VECN_H

template <unsigned int N>
class Vec {
protected:
    double _v[N];

public:
    Vec();
    Vec(const double[N]);

    double v(unsigned int) const;

    Vec<N> operator + (const Vec<N>&) const;
    Vec<N> operator - (const Vec<N>&) const;
    Vec<N> operator * (const Vec<N>&) const;

    Vec<N> operator * (double) const;
    Vec<N> operator / (double) const;

    Vec<N> operator - () const;
};

template <unsigned int N>
Vec<N>::Vec() {
    for(unsigned int i=0; i<N; i++) _v[i] = 0.;
}

template <unsigned int N>
Vec<N>::Vec(const double v[N]) {
    for(unsigned int i=0; i<N; i++) _v[i] = v[i];
}

template <unsigned int N>
inline double Vec<N>::v(unsigned int i) const {
    return _v[i];
}

template <unsigned int N>
inline Vec<N> Vec<N>::operator+(const Vec<N>& o) const {
    Vec<N> r;
    for(unsigned int i=0; i<N; i++) r._v[i] = _v[i] + o._v[i];
    return r;
}

template <unsigned int N>
inline Vec<N> Vec<N>::operator-(const Vec<N>& o) const {
    Vec<N> r;
    for(unsigned int i=0; i<N; i++) r._v[i] = _v[i] - o._v[i];
    return r;
}

template <unsigned int N>
inline Vec<N> Vec<N>::operator*(const Vec<N>& o) const {
    Vec<N> r;
    for(unsigned int i=0; i<N; i++) r._v[i] = _v[i] * o._v[i];
    return r;
}

template <unsigned int N>
inline Vec<N> Vec<N>::operator*(double o) const {
    Vec<N> r;
    for(unsigned int i=0; i<N; i++) r._v[i] = _v[i] * o;
    return r;
}

template <unsigned int N>
inline Vec<N> Vec<N>::operator/(double o) const {
    Vec<N> r;
    for(unsigned int i=0; i<N; i++) r._v[i] = _v[i] / o;
    return r;
}

template <unsigned int N>
inline Vec<N> Vec<N>::operator-() const {
    Vec<N> r;
    for(unsigned int i=0; i<N; i++) r._v[i] = -_v[i];
    return r;
}

#endif
