// problem1.cpp
// compile with
// c++ -o problem1 problem1.cpp
// execute with
// ./problem1
// author: Rajesh Rao

#include <iostream>

int main(){
  // variable declaration
  float a11, a12, a21, a22, b1, b2, y, x;

  // reading in input from the user for matrix elements
  std::cin >> a11 >> a12 >> a21 >> a22 >> b1 >> b2;

  // solved gaussian elimination on a 2x2 case, solving x, y
  y = (b2-(b1*(a21/a11))) / (a22-(a12*(a21/a11)));
  x =  (b1 - (a12*y))/a11;

  // outputs the resulting variables
  std::cout << "x:" <<  x  <<  "\n" << "y:" <<  y << "\n";

  return 0;

}
