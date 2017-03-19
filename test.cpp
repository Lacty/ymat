
#include <iostream>
#include <vector.h>


int main() {
  ymat::TVector<int> veci(3, 2);

  std::cout << "x " << veci[0] << std::endl;
  std::cout << "y " << veci[1] << std::endl;
  std::cout << "z " << veci[2] << std::endl;
}
