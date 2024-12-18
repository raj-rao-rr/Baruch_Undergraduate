#include <iostream>


int f(int n, int p, int a){
  int temp;
    if (n == 0){
      // terminal sequence has been reached at this point
      return a;
    }
    else{
      // declare a temporary variable to reduce calculations
      temp = f(n-1, p, a);
      // recursive sequence defining the (n+1) term
      return ((temp*temp)+temp+1)%p;
    }
}

int main() {
 int n, p, a;
 std::cin >> n >> p >> a;
 std::cout << f(n,p,a) << "\n";
 return 0;
}
