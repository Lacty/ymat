
#ifndef YMAT_MATRIX_H
#define YMAT_MATRIX_H

// ---------------------------------------------------
// Copyright (C) Akira Yanai 2017
// ---------------------------------------------------

#include <initializer_list>
#include <cassert>
#include <cmath>

#include "vector.h"


namespace ymat {
  
  // -------------------------------------------------------
  // Matrix 4x4
  // -------------------------------------------------------
  template < typename T >
  class TMatrix4 {
  public:
    T m00, m01, m02, m03,
      m10, m11, m12, m13,
      m20, m21, m22, m23,
      m30, m31, m32, m33;
  
    TMatrix4();
    TMatrix4(const TMatrix4&);
    TMatrix4(TMatrix4&&);
    TMatrix4(const std::initializer_list<T>&); 
  
    // -----------------------------------------------------
    // Util Funcs
    
    static std::size_t crow(); // count row
    static std::size_t ccol(); // count column
    
          T* ptr();
    const T* ptr() const;
    
    // make identity matrix
    void identity();
    
    // -----------------------------------------------------
    // Operators
    
    T* operator [](const std::size_t);
    const T* operator [](const std::size_t) const;
  };
  
  template< typename T >
  TMatrix4<T>::TMatrix4() {
    this->identity();
  }
  
  template< typename T >
  TMatrix4<T>::TMatrix4(const TMatrix4& rhs) {
    for (std::size_t i = 0; i < crow() * ccol(); i++) {
      this->ptr()[i] = rhs.ptr()[i];
    }
  }
  
  template< typename T >
  TMatrix4<T>::TMatrix4(TMatrix4&& rhs) {
    *this = rhs;
  }
  
  template< typename T >
  TMatrix4<T>::TMatrix4(const std::initializer_list<T>& list) {
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
  std::size_t TMatrix4<T>::crow() {
    return 4;
  }
  
  template< typename T >
  std::size_t TMatrix4<T>::ccol() {
    return 4;
  }
  
  template< typename T >
  T* TMatrix4<T>::ptr() {
    return &this->m00;
  }
  
  template< typename T >
  const T* TMatrix4<T>::ptr() const {
    return &this->m00;
  }
  
  template< typename T >
  void TMatrix4<T>::identity() {
    for (std::size_t i = 0; i < crow() * ccol(); i++) {
      this->ptr()[i] = (i % 5) ? 0 : 1;
    }
  }
  
  //
  // Operators
  //
  
  template< typename T >
  T* TMatrix4<T>::operator[](const std::size_t n) {
    assert(n >= 0 && n < crow());
    return (ptr() + n * crow());
  }
  
  template< typename T >
  const T* TMatrix4<T>::operator[](const std::size_t n) const {
    assert(n >= 0 && n < crow());
    return (ptr() + n * crow());
  }
}

#endif // YMAT_MATRIX_H