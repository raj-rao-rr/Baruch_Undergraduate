# Memory Management
C++ allows for memory management, from explicitly declaring types controling the size of each variable to more advanced uses of memory through pointers and references, 
which directly control memory flow.  

## Pointers
C++ copies the arguments to the functions when being passed. Hence, if we want to create functions that are mutators, or would like to reduce the time taken for computing this
additional step we will need to implement pointers `*` to point to a variable reference in memory.
```
#include <iostream>

// pass pointer arguments through reference
void add(int* pX, int* pY){
  (*pX)=(*pX)+1;  // * operator references a value
  (*pY)=(*pY)+2;
}

int main(){
  int x,y;
  x=5; y=7;
  add(&x,&y);   // & operator to reference address
  std::cout << "x=" << x << " and y=" << y << std::endl;
}
```
## References
C++ can also accomadate references `&` such that a function accepts variables that in memory, and simply modifies them at thier memory location, rather than creating a temporary
copy and forcing the user to return values for their function. 
```
#include <iostream>

// pass pointer arguments through reference
void add(int &pX, int &pY){
  pX=pX+1;  // perform operations normally
  pY=pY+2;
}

int main(){
  int x,y;
  x=5; y=7;
  add(x,y);   // & operator to reference address
  std::cout << "x=" << x << " and y=" << y << std::endl;
}
```

