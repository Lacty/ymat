
#include <iostream>
#include <vector.h>
#include <matrix.h>


using namespace ymat;

int main() {
  TVector<double> vec(1, 1, 1);
  
  TMatrix<double> tra;
  tra.translate(2, 2, 2);
  
  TMatrix<double> rot;
  rot.rotateX(3.14159265365);
  
  // OpenGLは左の方から
  //      回転 ← 移動
  vec *= rot * tra;
  
  std::cout << "x " << vec.x << std::endl;
  std::cout << "y " << vec.y << std::endl;
  std::cout << "z " << vec.z << std::endl;
}
