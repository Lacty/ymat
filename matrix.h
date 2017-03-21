
#ifndef YMAT_MATRIX_H
#define YMAT_MATRIX_H

// ---------------------------------------------------
// Copyright (C) Akira Yanai 2017
// ---------------------------------------------------

#include <iostream>
#include <iomanip>

#include <cmath>

#include <initializer_list>
#include <cassert>

#include "util.h"
#include "vector.h"


namespace ymat {
  
  // -------------------------------------------------------
  // Matrix 4x4
  // -------------------------------------------------------
  template < typename T >
  class TMatrix {
  public:
    T m00, m01, m02, m03,
      m10, m11, m12, m13,
      m20, m21, m22, m23,
      m30, m31, m32, m33;
  
    TMatrix();
    TMatrix(const TMatrix&);
    TMatrix(const TMatrix&&);
    TMatrix(const std::initializer_list<T>&);
  
    // -----------------------------------------------------
    // Util Funcs
    
    static std::size_t crow(); // count row
    static std::size_t ccol(); // count column
    
          T* ptr();
    const T* ptr() const;
    
    // initialize with 0
    void initialize();
    
    // make identity matrix
    void identity();
    
    // scale x, y, z
    template< typename U >
    TMatrix<T>& scale(const U, const U, const U);
    
    // translate x, y, z
    template< typename U >
    TMatrix<T>& translate(const U, const U, const U);
    
    template< typename U >
    TMatrix<T>& rotateX(const U);
    
    template< typename U >
    TMatrix<T>& rotateY(const U);
    
    template< typename U >
    TMatrix<T>& rotateZ(const U);
    
    // rotate x, y, z
    template< typename U >
    TMatrix<T>& rotate(const U, const U, const U);
    
    // -----------------------------------------------------
    // Operators
    
    T* operator [](const std::size_t);
    const T* operator [](const std::size_t) const;
    
    TMatrix<T>& operator =(const TMatrix<T>&);
    TMatrix<T> operator *(const TMatrix<T>&) const;
    TMatrix<T>& operator *=(const TMatrix<T>&);
    
    friend std::ostream& operator<<(std::ostream& os, const TMatrix<T>& src) {
      for (std::size_t r = 0; r < crow(); r++) {
        if (!r) os << "[";
        else os << " ";
        for (std::size_t c = 0; c < ccol(); c++) {
          os << std::setw(8) << floor2(src[r][c], 3) << ",";
        }
        if (r == crow() - 1) os << "]";
        else os << std::endl;
      }
      return os;
    }
  };
  
  template< typename T >
  TMatrix<T>::TMatrix() {
    this->identity();
  }
  
  template< typename T >
  TMatrix<T>::TMatrix(const TMatrix& rhs) {
    for (std::size_t i = 0; i < crow() * ccol(); i++) {
      this->ptr()[i] = rhs.ptr()[i];
    }
  }
  
  template< typename T >
  TMatrix<T>::TMatrix(const TMatrix&& rhs) {
    *this = rhs;
  }
  
  template< typename T >
  TMatrix<T>::TMatrix(const std::initializer_list<T>& list) {
    assert(list.size() == crow() * ccol());
    std::size_t n = 0;
    for (auto&& x : list) {
      this->ptr()[n] = x;
      ++n;
    }
  }
  
  //
  // Util Funcs
  //
  
  template< typename T >
  std::size_t TMatrix<T>::crow() {
    return 4;
  }
  
  template< typename T >
  std::size_t TMatrix<T>::ccol() {
    return 4;
  }
  
  template< typename T >
  T* TMatrix<T>::ptr() {
    return &this->m00;
  }
  
  template< typename T >
  const T* TMatrix<T>::ptr() const {
    return &this->m00;
  }
  
  template< typename T >
  void TMatrix<T>::initialize() {
    for (std::size_t i = 0; i < crow() * ccol(); i++) {
      this->ptr()[i] = 0;
    }
  }
  
  template< typename T >
  void TMatrix<T>::identity() {
    for (std::size_t i = 0; i < crow() * ccol(); i++) {
      this->ptr()[i] = (i % 5) ? 0 : 1;
    }
  }
  
  template< typename T >
  template< typename U >
  TMatrix<T>& TMatrix<T>::scale(const U x, const U y, const U z) {
    this->m00 = x;
    this->m11 = y;
    this->m22 = z;
    return *this;
  }
  
  template< typename T >
  template< typename U >
  TMatrix<T>& TMatrix<T>::translate(const U x, const U y, const U z) {
    this->m03 = x;
    this->m13 = y;
    this->m23 = z;
    return *this;
  }
  
  template< typename T >
  template< typename U >
  TMatrix<T>& TMatrix<T>::rotateX(const U val) {
    TMatrix<T> t{
      1,        0,         0, 0,
      0, cos(val), -sin(val), 0,
      0, sin(val),  cos(val), 0,
      0,        0,         0, 1
    };
    *this *= t;
    return *this;
  }
  
  template< typename T >
  template< typename U >
  TMatrix<T>& TMatrix<T>::rotateY(const U val) {
    TMatrix<T> t{
       cos(val), 0, sin(val), 0,
              0, 1,        0, 0,
      -sin(val), 0, cos(val), 0,
              0, 0,        0, 1
    };
    *this *= t;
    return *this;
  }
  
  template< typename T >
  template< typename U >
  TMatrix<T>& TMatrix<T>::rotateZ(const U val) {
    TMatrix<T> t{
      cos(val), -sin(val), 0, 0,
      sin(val),  cos(val), 0, 0,
             0,         0, 1, 0,
             0,         0, 0, 1
    };
    *this *= t;
    return *this;
  }
  
  template< typename T >
  template< typename U >
  TMatrix<T>& TMatrix<T>::rotate(const U x, const U y, const U z) {
    rotateX(x);
    rotateY(y);
    rotateZ(z);
    return *this;
  }
  
  //
  // Operators
  //
  
  template< typename T >
  T* TMatrix<T>::operator[](const std::size_t n) {
    assert(n >= 0 && n < crow());
    return (ptr() + n * crow());
  }
  
  template< typename T >
  const T* TMatrix<T>::operator[](const std::size_t n) const {
    assert(n >= 0 && n < crow());
    return (ptr() + n * crow());
  }
  
  template< typename T >
  TMatrix<T>& TMatrix<T>::operator =(const TMatrix<T>& rhs) {
    for (std::size_t i = 0; i < crow() * ccol(); i++) {
      this->ptr()[i] = rhs.ptr()[i];
    }
    return *this;
  }
  
  template< typename T >
  TMatrix<T> TMatrix<T>::operator *(const TMatrix<T>& rhs) const {
    TMatrix<T> tmp;
    tmp.initialize();
    for (std::size_t r = 0; r < crow(); r++) {
      for (std::size_t c = 0; c < ccol(); c++) {
        for (std::size_t c2 = 0; c2 < ccol(); c2++) {
          tmp[r][c] += (*this)[r][c2] * rhs[c2][c];
        }
      }
    }
    return tmp;
  }
  
  template< typename T >
  TMatrix<T>& TMatrix<T>::operator *=(const TMatrix<T>& rhs) {
    (*this) = (*this) * rhs;
    return *this;
  }
}

#endif // YMAT_MATRIX_H