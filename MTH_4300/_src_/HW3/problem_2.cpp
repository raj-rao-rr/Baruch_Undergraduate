#include <iostream>

// Function declaration
int power (int, int);
int swaps (int, int, int, int);


// calculates the value of x^a
int power(int x, int a){
  int val = 1;
  // iterates through to the power of a, multiplying x to itself a times
  for (int i = 0; i < a; ++i){
    val *= x;
  }
  return val;
}

// recursive function for counting the number of swaps (defined as sum sequences)
int swaps(int x, int a, int i, int s){
  int val, count = 0;
  // we will use i as a measure of starting value (1, 2, 3,...) and s for the rolling sum with which we will keep track of

  // if x = 1 then all powers of 1 are accounted for only by 1
  if (x == 1){
    return 1;
  }
  else{
    val = power(i, a);
    // if the current sum is less than the assigned value then we add to sum and itterate the element (i) for the additive sequence
    while (val + s < x){
      count += swaps(x, a, i+1, s+val);
      ++i;
      val = power(i, a);
    }
    // if the rolling sum matches the given sum asigned, we add one to the counter
    if (val + s == x){
      ++count;
    }
  }
  return count;
}

// main code for execution
int main() {
 int x, a, i, s;
 // user inputs a value [x] to sum to, and a positive power [a]
 std::cin >> x >> a;
 std::cout << swaps(x,a, i=1, s=0) << "\n";
 return 0;
}
