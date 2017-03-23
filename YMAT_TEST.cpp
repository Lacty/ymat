
#include <iostream>
#include <vector.h>
#include <matrix.h>

using namespace ymat;
using Vec = TVector<double>;
using Mat = TMatrix<double>;


int main() {
  Vec pos(1, 1, 0);
  
  Mat translate(Translation<double>(10, 0, 0));
  // Mat rotate(Rotation<double>(0, 1, 0));
  std::cout << translate << std::endl;
  
  pos *= translate;
  
  std::cout << pos << std::endl;
}