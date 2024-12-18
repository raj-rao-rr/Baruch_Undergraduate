# Basics C++

### Installation 
We will be using [Microsoft Visual studio](https://visualstudio.microsoft.com/vs/features/cplusplus/) for our C++ IDE and compiler. All simple code will be written with 
the following prerequisites provided within each `.cpp` file. As we develop more complicated scripts, these prerequisites will become more lax.  
```
#include <iostream>

// main function to run code
int main(){
  // body of execution code
}
```
Prior to executing our C++ code, we will need to compile each `.cpp` file, creating an `.exe` (executable) to run from the visual studio command line

```
**********************************************************************
** Visual Studio 2019 Developer Command Prompt v16.5.3
** Copyright (c) 2019 Microsoft Corporation
**********************************************************************

// To compile the .cpp file
C:\Program Files (x86)\Microsoft Visual Studio\2019\Community> cl filename.cpp

// To run the .exe file
C:\Program Files (x86)\Microsoft Visual Studio\2019\Community> filename.exe
```

### Syntax Basics
Since C++ is a statically typed language, the type of the variable is known at compile-time instead of at run-time as with dynamically typed langauges like Python. 
Advantages of this include:
- Improved debugging, being able to error check early on in development
- Increased efficiency, being able to more efficiently allocate memory

Lets create a variable x, and set it equal to 10. **Notice that we end each line with a semi-colon (;)** - this signifies the termination of a statement. 
```
int x; 
x = 5
```
Here is the complete list of fundamental types in C++:

| Type names | Notes on size / precision |
| --- | --- |
| char | Exactly one byte in size. At least 8 bits |
| char16_t | Not smaller than char. At least 16 bits|
| char32_t	| Not smaller than char16_t. At least 32 bits|
| wchar_t	| Can represent the largest supported character set|
| signed short int	|Not smaller than char. At least 16 bits|
| signed int	|Not smaller than short. At least 16 bits|
| signed long int|	Not smaller than int. At least 32 bits|
| signed long long int|	Not smaller than long. At least 64 bits|
| Integer types (unsigned)|	unsigned char	(same size as their signed counterparts)|
| double|	Precision not less than float |
| long double	|Precision not less than double |
| Boolean type	|bool	|
| Void type|	void	no storage|

These variables can be set either through construction or assignment, with _**construction**_ occuring at type declaration and _**assignment**_ occuring post declaration.
```
//contruction 
int x = 10;

//assignment
int x; 
x = 10; 
```

### Standard Input and Output
To read in standard in/output from the computer, we call the standard `std` library from `iostream` and direct the flow of keyboard input. This follows as such:
```
#inlcude <iostream>

int main(){
  int input; 
  
  std::cin >> input;    // reads in input from user, stores it in variable input
  
  std::cout << input;   // prints the variable input to the screen
}
```
We can also write output to the screen using the `printf` function, where we specify the type of variable we are passing 
```
int x = 22;
printf('I am %d years old\n', x);
```
### Summary
Bringing it all together we have a test example, which encorprates the newly learned information.
```
#inlcude <iostream>

int main(){
  int x, y, mult;
  double div;
  // reads in input from user, stores it in variable input
  std::cin >> x >> y;    
  // outputs messages to screen
  std::cout << 'x multiplied by y is ' << x * y; 
  
  div =  x / y;
  std::cout << 'x divided by y is ' << div; 
  div = y / x;
  std::cout << 'y divided by x is ' << div; 
}
```
