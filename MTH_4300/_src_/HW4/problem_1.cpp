#include <iostream>


void modify(long** px, long n, long s){
  int x, shift = 0;

  // initialize a new array measure with new length size
  long *y;
  y = new long[s];

  // itterating through the original array that we defiend
  for (int i = 0; i < n ; ++i){
    x = (*px)[i];

    // if x is 0 we add three zeros and adjust our shift method
    if (x == 0){
      for (int j = 0; j < 3; ++j){
        y[i+shift] = 1;
        ++shift; // we compute the shift from our initial i-th position
      }
      --shift; //one space is accounted for with the original zero, we subtract that
    }
    else if (x != 5){
      y[i+shift] = (*px)[i]; // if not five we simply add to the sequence
    }
    else {
     --shift; // if equal to five we move back one space on the shfit
    }
  }

  // delete the memory of old values for *px and reassin to y-address
  delete[] *px;
  *px = y;
}


int main() {
  long n, x, s, zeros = 0, fives=0;
  std::cout << "How many elements would you like to enter" << "\n";
  std::cin >> n;

  // define our intial sequence as a pointer to array
  long *arr;
  arr = new long[n];

  // insert values into sequence-array and counts the zero/five appearances
  std::cout << "Enter your elements into the array" << "\n";
  for(int i = 0; i < n; ++i){
    std::cin >> x;
    if (x == 0){
      ++zeros;
    }
    else if (x == 5){
      ++fives;
    }
    *(arr+i) = x;
  }

  s = n + 2*zeros - fives;
  // modify our existing list with new size of 3x0 (000) less number of fives
  modify(&arr, n, s);

  std::cout << "This is your modified array" << "\n";
  // print our the elements in our array
  for (int j = 0; j < s; ++j){
    std::cout << *(arr + j) << " ";
  }

  std::cout << "\n";
  return 0;
}
