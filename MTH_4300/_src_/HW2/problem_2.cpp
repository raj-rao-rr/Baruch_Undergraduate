// problem2.cpp
// compile with
// c++ -o problem2 problem2.cpp
// execute with
// ./problem2
// author: Rajesh Rao

#include <iostream>

int main(){
    // variable declaration
    int m, a, b, c;
    bool check;

    // reading in inputs for the given condition function
    std::cin >> m >> a >> b >> c;

    // check all numbers to m - before which must exist a multiple
    for (int i = 0; i<=m; i++){
        // create a conditional check to the itterated value of i
         if ((a*i+b)%m==c){
             check = true; // checks to see if such x exists
             std::cout << i << "\n";
             break;
         }
         else{
             check = false;
         }
    }

    // if no sufficient x is found, print a single statment
    if (check == false){
      std::cout << "There is no such x." << "\n";
    }

    return 0;
}
