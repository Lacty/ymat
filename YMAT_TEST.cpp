
#include <iostream>
#include <vector.h>
#include <matrix.h>


using namespace ymat;

int main() {
  // make 3-dimensional vector(x, y, z)
  // ベクトル生成
  TVector<double> vec(3, 4, 2);
  
  // make identity matrix 4x4
  // 行列生成
  // 何も指定してないので単位行列
  TMatrix4<double> mat;
  
  // can also explicitly be an identity matrix
  // 明示的に単位行列にもできる
  // mat.identity();
  
  // ベクトルに行列をかけ合わせる
  vec *= mat;
  
  std::cout << "x " << vec.x << std::endl; // 3
  std::cout << "y " << vec.y << std::endl; // 4
  std::cout << "z " << vec.z << std::endl; // 2
}
