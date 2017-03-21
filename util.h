
#ifndef YMAT_UTIL_H
#define YMAT_UTIL_H

// ---------------------------------------------------
// Copyright (C) Akira Yanai 2017
// ---------------------------------------------------

#include <cmath>

namespace ymat {
  
  // 小数第N位切り捨て
  double floor2(double dIn, int nLen)
  {
      double dOut;
   
      dOut = dIn * pow(10.0, nLen);
      dOut = (double)(int)(dOut);
   
      return dOut * pow(10.0, -nLen);
  }
  
}

#endif // YMAT_UTIL_H