
#include <iostream>
#include <vector.h>


int main() {
  ymat::TVector<int> veci(3, 2);

  int* ptr = veci.ptr();
  std::cout << "x " << *ptr << std::endl;
  std::cout << "x " << *(++ptr) << std::endl;
  std::cout << "x " << *(++ptr) << std::endl;
}
