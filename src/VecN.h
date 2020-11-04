#ifndef __VECN_H
#define __VECN_H

/**
 * \class Vec
 * @tparam N dimension number.
 * \brief N-dimensional vector.
 */
template <unsigned int N>
class Vec {
protected:
    double _v[N];  ///< Vec field.

public:
    /**
     * \brief default Vec constructor
     * Initializes all values at 0.
     */
    Vec();

    /**
     * \brief Vec constructor with an initialisation list.
     * @param v initialisation list.
     */
    Vec(const double v[N]);

    /**
     * \brief field value getter.
     * \param i field index.
     * @return field value.
     */
    double v(unsigned int i) const;

    /**
     * \brief addition operator between 2 Vec.
     * @param o other Vec.
     * @return resulting Vec.
     */
    Vec<N> operator + (const Vec<N>& o) const;

    /**
     * \brief subtraction operator between 2 Vec.
     * @param o other Vec.
     * @return resulting Vec.
     */
    Vec<N> operator - (const Vec<N>& o) const;

    /**
     * \brief term to term multiplication between 2 Vec.
     * @param o other Vec.
     * @return resulting Vec.
     */
    Vec<N> operator * (const Vec<N>& o) const;

    /**
     * \brief scalar multiplication.
     * \param o scalar used.
     * @return resulting Vec
     */
    Vec<N> operator * (double o) const;

    /**
     * \brief scalar division.
     * \param o scalar used.
     * @return resulting Vec
     */
    Vec<N> operator / (double o) const;

    /**
     * \brief Vec negation.
     * @return Vec with negated coordinates.
     */
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
