
#include <iostream>
#include <vector.h>
#include <matrix.h>


using namespace ymat;

int main() {
  TMatrix4x4<float> mat{
    1.0f, 0.0f, 3.0f, 0.0f,
    0.0f, 1.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 1.0f
  };
  
  std::cout << mat[0][2] << std::endl;
}
