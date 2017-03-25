
#include <iostream>
#include <ymat.h>

using namespace ymat;
using Vec = TVector<double>;
using Mat = TMatrix<double>;


int main() {
  Vec vec;
  Mat translate(Translation<double>(10, 0, 0));
  Mat rotate(Rotation<double>(0, M_PI, 0));

  vec *= translate;
  std::cout << vec << std::endl; // [10, 0, 0]  
  
  vec *= rotate;  
  std::cout << vec << std::endl; // [-10, 0, 0]
}