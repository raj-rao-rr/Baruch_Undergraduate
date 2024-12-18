// problem3.cpp
// compile with
// c++ -o problem3 problem3.cpp
// execute with
// ./problem3
// author: Rajesh Rao

#include <iostream>

int main() {
 int first, current, prior, input = 0, swaps = 0, i = 0;

 // itterate through the user's inputs (stopping once user enters -1)
 while (input != -1){
   std::cin >> input;

   // begin by declaring the first element in the sequence
   // we keep track of the change in accordance to the first swap
   if (i == 0){
     first = input;
   }
   else if (i == 1){
     current = input;
   }
   else{
     // once we have entered 2 elements to the sequence we begin the loop
     prior = current;
     current = input;

     // conditional logic begining when the nth and n-1 element in the sequence
     if (current != prior){
       // conditioning logic to detemine the swap aggrement (e.g. 1, 2, 3)
       if ((current + prior) == 3){
         first = 3;
         current = first;
         ++swaps; //keeps track of all the swaps (# of swaps = length of the transformed sequence)
       }
       else if ((current + prior) == 4){
         first = 2;
         current = first;
         ++swaps;
       }
       else if ((current + prior) == 5){
         first = 1;
         current = first;
         ++swaps;
       }
     }
   }
   // continually look to iterate over the assigned values
   ++i;
 }

 // once the first term is set, we itteratively print to the number of swaps
 for (int x = 0; x < swaps; x++){
   std::cout << first << " ";
 }
 std::cout << "\n";

 return 0;
}
