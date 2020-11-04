#ifndef __MATN_H
#define __MATN_H
#include "VecN.h"

/**
 * \class Mat
 * @tparam N
 * \brief N-dimensional matrix
 */
template <unsigned int N>
class Mat {
protected:
    double _v[N][N];  ///< Mat field

public:
    /**
     * \brief default Mat constructor
     * Initializes all values at 0.
     */
    Mat();

    /**
     * \brief Mat constructor with an initialisation table.
     * @param v
     */
    Mat(const double v[N][N]);

    /**
     * \brief Mat constructor with an initialisation list.
     * @param v initialisation list.
     */
    Mat(const double v[N*N]);

    /**
     * \brief field value getter.
     * @param i first coordinate.
     * @param j second coordinate.
     * @return field value.
     */
    double v(unsigned int i, unsigned int j) const;

    /**
     * \brief addition operator between 2 Mat.
     * @param o other Mat.
     * @return resulting Mat.
     */
    Mat<N> operator + (const Mat<N>& o) const;

    /**
     * \brief subtraction operator between 2 Mat.
     * @param o other Mat.
     * @return resulting Mat.
     */
    Mat<N> operator - (const Mat<N>& o) const;

    /**
     * \brief scalar multiplication.
     * \param o scalar used.
     * @return resulting Mat
     */
    Mat<N> operator * (double o) const;

    /**
     * \brief scalar division.
     * \param o scalar used.
     * @return resulting Mat
     */
    Mat<N> operator / (double o) const;

    /**
     * \brief Mat negation.
     * @return Mat with negated coordinates.
     */
    Mat<N> operator - () const;


    /**
     * \brief multiplication by a vector.
     * @param o Vec for the multiplication.
     * @return multiplied Mat
     */
    Vec<N> operator * (const Vec<N>& o) const;
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
