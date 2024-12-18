#include <iostream>

// solves for the power of a given number
// e.g. x^2 = x * x
int power(int x, int a){
  int val = 1;
  for (int i = 0; i < a; ++i){
    val *= x;
  }
  return val;
}

// recursive function for counting the number of swaps
int swaps(int n, int a, int first, int sum, int k, int minK){
  int val, count=0;
  val = power(first, a);
  // if the current sum is less than the assigned value
  // we continue to check numbers itterartively
  while (val + sum < n){
    // we look to keep a rolling track of the minimum
    // number of terms to a given sum
    minK = swaps(n, a, first+1, sum+val, k+1, minK);
    ++first;
    val = power(first, a);
  }

  // check to see if our rolling sum equals our N
  if (val + sum == n){
    // if the value matches the given sum we modify the
    // minimum number of terms required to equal it
    if (k < minK){
      minK = k;
    }
  }

  return minK;
}

int main() {
  int x, a, i, s, mK, k;
  std::cin >> x >> a;
  // we initialize mK to be a very large number
  std::cout << swaps(x,a, i=1, s=0, k=1, mK=100) << "\n";
  return 0;
}
