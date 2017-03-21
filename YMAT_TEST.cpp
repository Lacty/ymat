
#include <iostream>
#include <vector.h>
#include <matrix.h>


using namespace ymat;

int main() {
  TVector<double> vec(3, 4, 2);
  
  TMatrix<double> mat1;
  mat1.translate(1, 1, 1);
  
  TMatrix<double> mat2;
  mat2.translate(2, 2, 2);
  
  vec *= mat1 * mat2;
  
  std::cout << "x " << vec.x << std::endl; // 6
  std::cout << "y " << vec.y << std::endl; // 7
  std::cout << "z " << vec.z << std::endl; // 5
}
