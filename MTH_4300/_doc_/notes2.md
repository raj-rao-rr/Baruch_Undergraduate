# Developing Structure
We now will consider syntax for developing the basic building blocks of programs. 
### Decsions
We consider two basic decision structures that allow for conditional logic when performing operations. These will be the standard if statement and switch statment. 

We begin with an **if** statement, and it's natural extension **else if** and **else**.
```
if(boolean_expression) {
   // statement(s) will execute if the boolean expression is true
} 
else if (boolean_expression) {
  // statement(s) will execute if the boolean expression is true
} 
else {
  // statement(s) will execute if all other boolean expression(s) is/are false
}
```
There also exists **switch** statements, that operate slightly different to the tradtional if-statement, which directs the flow of information through checks. The switch-statement works by first initializing an expression (encapsulated within the switch parentheses) and following by creating cases that represent conditions for said expression.   
 ```
 switch(expression) {
   case constant-expression  :
      statement(s);
      break; //optional
   case constant-expression  :
      statement(s);
      break; //optional
  
   // you can have any number of case statements.
   default : //Optional
      statement(s);
}
```
### Loops 
There are three major loop structures that we will be discussing **while**, **for**, and **do while** loops. We will start with the common "while loop:

A while loop statement repeatedly executes a target statement as long as a given condition is true, testing the condition before executing the loop body
```
while(condition) {
   statement(s);
}
```
A variant of the while loop is the do-while loop, that tests the condition at the end of the loop body rather than the begining 
```
do {
   statement(s);
} 
while( condition );
```
Finally, we have the for loop that executes a sequence of statements multiple times and abbreviates the code that manages the loop variable. Basically a condensed while loop.
```
for ( init; condition; increment ) {
   statement(s);
}
```
### Functions
A function is a group of statements that together perform a task. Every C++ program has at least one function, which is `main()`, as we defined earlier. General C++ functions consists of a return type to catergorize the output values expected from the function, the function name, the list of parameters and the body of the function. 
```
return_type function_name( parameter list ) {
   body of the function
}
```
Prior to running a function, it is important to declare them at the top of your program, informing the compiler about a function and how to call it. Declarations are written as follows:
```
return_type function_name( parameter list );
```
There also exists special functions types, namely **void**, that return nothing. These are commonly used in special output functions and are declare using the `void` keyword
```
void function_name( parameter list ) {
   body of the function
}
```

### Summary
Bringing it all together we have a test example, which encorprates the newly learned information.
```
#include <iostream>
 
// function declaration
int oddEven(int);
 
int main () {
   // local variable declaration:
   int a = 100;
   int itter;
 
   // print quadratic expression for numbers
   for (itter=0; itter < a; ++itter){
      specialPrint(itter)
   }
 
   return 0;
}

// function printing a quadratic expression for even/odd numbers
void specialPrint(int num){
   int val = oddEven(num);
   
   if (val == 0){
      std::cout << '{' << num*num + 2*num - 7 << '}\n';
   } else {
      std::cout << '{' << num*num + 5*num - 18 << '}\n';
   }
}

// function returning the the even/odd nature of a number
int oddEven(int num1) {
   // local variable declaration
   int result = 0;
 
   if ((num1 % 2) == 0) {
      return 1;
   } else {
      return 0;
   } 
}
```
