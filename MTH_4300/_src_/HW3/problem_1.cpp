#include <iostream>

// function initilization
int divisor(int n){
  // will calculate the number of divisors for a given number
  // eg. divisor(10) = 4 {1,2,5,10}
 int count = 0, i=1;

// itterates through the value and determines divisibility through modulus
 while (i <= n){
   // if n is dividible by i there exists no remainder and we add to count
   if (n%i == 0){
     ++count;
   }
   ++i;
 }
 return count;
}

// function declaration (must be present to execute script)
int divisor(int);

// primary function execution
int main() {
 int num, i = 1, sum = 0;
 std::cin >> num;

 // itterates through all integers up to value specified by user
 // adds a rolling sum to the number of divisors present per each integer
 while (i <= num){
   sum += divisor(i);
   ++i;
 }

 std::cout << sum << "\n";
 return 0;
}
