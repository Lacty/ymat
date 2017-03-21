
#ifndef YMAT_VECTOR_H
#define YMAT_VECTOR_H

// ---------------------------------------------------
// Copyright (C) Akira Yanai 2017
// ---------------------------------------------------

#include <cassert>
#include <cmath>

#include "matrix.h"


namespace ymat {

  // --------------------------------------------------------
  // Vector
  // --------------------------------------------------------
  template< typename T >
  class TVector {
  public:
    T x, y, z;
    
    TVector();
    TVector(const T, const T);
    TVector(const T, const T, const T);
    TVector(const TVector<T>&);
    TVector(const TVector<T>&&);
    
    // ------------------------------------------------------
    // Util Funcs
    
    // return dimension
    static std::size_t dim();
    
          T* ptr();
    const T* ptr() const;
    
    double     length() const;
    double     dist(const TVector<T>&) const;
    double     dot(const TVector<T>&) const;
    TVector<T> cross(const TVector<T>&) const;
    
    TVector<T> normalize();
    TVector<T> normalized();
    
    // ------------------------------------------------------
    // Operators
    
    T& operator [](const std::size_t);
    const T& operator [](const std::size_t) const;
    
    TVector<T>& operator =(const TVector<T>&);
    
    TVector<T> operator +(const TVector<T>&) const;
    TVector<T> operator -(const TVector<T>&) const;
    TVector<T> operator -() const;
    TVector<T> operator *(const TVector<T>&) const;
    TVector<T> operator *(const T) const;
    TVector<T> operator /(const TVector<T>&) const;
    TVector<T> operator /(const T) const;
    
    TVector<T>& operator +=(const TVector<T>&);
    TVector<T>& operator -=(const TVector<T>&);
    TVector<T>& operator *=(const TVector<T>&);
    TVector<T>& operator *=(const T);
    TVector<T>& operator /=(const TVector<T>&);
    TVector<T>& operator /=(const T);
    
    template< typename M >
    TVector<T>& operator *=(const TMatrix<M>&);
  };
  
  //
  // Constructors
  //
  
  template< typename T >
  inline TVector<T>::TVector()
    : x(0), y(0), z(0)
    {}
  
  template< typename T >
  inline TVector<T>::TVector(const T x, const T y)
    : x(x), y(y), z(0)
    {}
  
  template< typename T >
  inline TVector<T>::TVector(const T x, const T y, const T z)
    : x(x), y(y), z(z)
    {}
  
  template< typename T >
  inline TVector<T>::TVector(const TVector<T>& src)
    : x(src.x), y(src.y), z(src.z)
    {}
  
  template< typename T >
  inline TVector<T>::TVector(const TVector<T>&& src)
    : x(src.x), y(src.y), z(src.z)
    {}
  
  //
  // Util Funcs
  //
  
  template< typename T >
  std::size_t TVector<T>::dim() {
    return 3;
  }
  
  template< typename T >
  T* TVector<T>::ptr() {
    return &this->x;
  }
  
  template< typename T >
  const T* TVector<T>::ptr() const {
    return &this->x;
  }
  
  template< typename T >
  double TVector<T>::length() const {
    return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
  }
  
  template< typename T >
  double TVector<T>::dist(const TVector<T>& rhs) const {
    return (*this - rhs).length();
  }
  
  template< typename T >
  double TVector<T>::dot(const TVector<T>& rhs) const {
    return this->x * rhs.x + this->y * rhs.y + this->z * rhs.z;
  }
  
  template< typename T >
  TVector<T> TVector<T>::cross(const TVector<T>& rhs) const {
    return TVector<T>(this->y * rhs.z - rhs.y * this->z, this->z * rhs.x - rhs.z * this->x, this->x * rhs.y - rhs.x * this->y);
  }
  
  template< typename T >
  TVector<T> TVector<T>::normalize() {
    double length = this->length();
    if (length != 0) {
      *this /= length;
    }
    return *this;
  }

  template< typename T >
  TVector<T> TVector<T>::normalized() {
    auto tmp(*this);
    double length = this->length();
    if (length != 0) {
      tmp /= length;
    }
    return tmp;
  }

  //
  // Operators
  //
  
  template< typename T >
  T& TVector<T>::operator [](const std::size_t n) {
    assert(n >= 0 && n < dim());
    return *(ptr() + n);
  }
  
  template< typename T >
  const T& TVector<T>::operator [](const std::size_t n) const {
    assert(n >= 0 && n < dim());
    return *(ptr() + n);
  }
  
  template< typename T >
  TVector<T>& TVector<T>::operator =(const TVector<T>& rhs) {
    this->x = rhs.x;
    this->y = rhs.y;
    this->z = rhs.z;
    return *this;
  }
  
  template< typename T >
  inline TVector<T> TVector<T>::operator +(const TVector<T>& rhs) const {
    return TVector<T>(*this) += rhs;
  }
  
  template< typename T >
  inline TVector<T> TVector<T>::operator -(const TVector<T>& rhs) const {
    return TVector<T>(*this) -= rhs;
  }
  
  template< typename T >
  inline TVector<T> TVector<T>::operator -() const {
    return TVector<T>(*this) *= -1;
  }
  
  template< typename T >
  inline TVector<T> TVector<T>::operator *(const TVector<T>& rhs) const {
    return TVector<T>(this->x * rhs.x,
                      this->y * rhs.y,
                      this->z * rhs.z);
  }
  
  template< typename T >
  inline TVector<T> TVector<T>::operator *(const T rhs) const {
    return TVector<T>(this->x * rhs,
                      this->y * rhs,
                      this->z * rhs);
  }
  
  template< typename T >
  inline TVector<T> TVector<T>::operator /(const TVector<T>& rhs) const {
    return TVector<T>(this->x / rhs.x,
                      this->y / rhs.y,
                      this->z / rhs.z);
  }
  
  template< typename T >
  inline TVector<T> TVector<T>::operator /(const T rhs) const {
    return TVector<T>(this->x / rhs,
                      this->y / rhs,
                      this->z / rhs);
  }
  
  template< typename T >
  inline TVector<T>& TVector<T>::operator +=(const TVector<T>& rhs) {
    this->x += rhs.x;
    this->y += rhs.y;
    this->z += rhs.z;
    return *this;
  }
  
  template< typename T >
  inline TVector<T>& TVector<T>::operator -=(const TVector<T>& rhs) {
    this->x -= rhs.x;
    this->y -= rhs.y;
    this->z -= rhs.z;
    return *this;
  }
  
  template< typename T >
  inline TVector<T>& TVector<T>::operator *=(const TVector<T>& rhs) {
    this->x *= rhs.x;
    this->y *= rhs.y;
    this->z *= rhs.z;
    return *this;
  }
  
  template< typename T >
  inline TVector<T>& TVector<T>::operator *=(const T rhs) {
    this->x *= rhs;
    this->y *= rhs;
    this->z *= rhs;
    return *this;
  }
  
  template< typename T >
  inline TVector<T>& TVector<T>::operator /=(const TVector<T>& rhs) {
    this->x /= rhs.x;
    this->y /= rhs.y;
    this->z /= rhs.z;
    return *this;
  }
  
  template< typename T >
  inline TVector<T>& TVector<T>::operator /=(const T rhs) {
    this->x /= rhs;
    this->y /= rhs;
    this->z /= rhs;
    return *this;
  }
  
  template< typename T >
  template< typename M >
  TVector<T>& TVector<T>::operator *=(const TMatrix<M>& rhs) {
    for (std::size_t i = 0; i < dim(); i++) {
      (*this)[i] = rhs[i][0] * (*this)[0]
                 + rhs[i][1] * (*this)[1]
                 + rhs[i][2] * (*this)[2]
                 + rhs[i][3] * 1;
    }
    return *this;
  }
}

#endif // YMAT_VECTOR_H