
#include <iostream>
#include <vector.h>
#include <matrix.h>

using namespace ymat;


int main() {
  TVector<double> vec(10, 0, 0);
  TMatrix<double> mat;
  
  mat.scale(2, 2, 2);
  mat.rotate(0.0, 3.14159265, 0.0);
  
  vec *= mat;
  
  std::cout << mat << std::endl;  
  std::cout << vec << std::endl;
}