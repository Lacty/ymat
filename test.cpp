
#include <iostream>
#include <vector.h>


using namespace ymat;

int main() {
  TVector<double> vec(3, 2);

  std::cout << "length = " << vec.length() << std::endl;
  std::cout << "x = " << vec.x << std::endl;
  std::cout << "y = " << vec.y << std::endl;
  std::cout << "z = " << vec.z << std::endl;
  
  vec.normalize();
  std::cout << "x = " << vec.x << std::endl;
  std::cout << "y = " << vec.y << std::endl;
  std::cout << "z = " << vec.z << std::endl;
  
  std::cout << "length = " << vec.length() << std::endl;
}
