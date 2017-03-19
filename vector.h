
#ifndef YMAT_VECTOR_H
#define YMAT_VECTOR_H

// ---------------------------------------------------
// Copyright (C) Akira Yanai 2017
// ---------------------------------------------------

#include <iostream>
#include <cmath>


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
    TVector(TVector<T>&&);
    
    T& operator [](std::size_t);
    
    TVector<T> operator =(const TVector<T>&);
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
    
    T* ptr();
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
  inline TVector<T>::TVector(TVector<T>&& src)
    : x(src.x), y(src.y), z(src.z)
    {}

  //
  // Operators
  //
  
  /*template< typename T >
  T& TVector<T>::operator [](std::size_t) {
    return 
  }*/
  
  template< typename T >
  inline TVector<T> TVector<T>::operator =(const TVector<T>& rhs) {
    *this = rhs;
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
  
  //
  // Util Funcs
  //
  
  template< typename T >
  T* TVector<T>::ptr() {
    return &this->x;
  }
}

#endif // YMAT_VECTOR_H