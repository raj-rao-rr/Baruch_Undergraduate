#include <iostream>


// merges two sequences into a larger sequence based on values
long *mMerge(long *aX, long *aY, long xlen, long ylen, long len){
  // create a temporary array to return the updated merge sequence
  long *aZ;
  aZ = new long[len];
  long xPos=0, yPos=0, zPos=0;

  while (zPos < len){
   // if we have exceed the increment of our sub-sequence
   // we simply attach the remaining sequence
   if (xPos == xlen){
     aZ[zPos] = aY[yPos];
     ++yPos;
   }
   else if (yPos == ylen){
     aZ[zPos] = aX[xPos];
     ++xPos;
   }
   else{
     // check to see the first sorted sequence at each index position
     if (aX[xPos] > aY[yPos]){
      aZ[zPos] = aY[yPos];
      ++yPos;
     }
     else if (aX[xPos] < aY[yPos]){
       aZ[zPos] = aX[xPos];
       ++xPos;
     }
   }
   // increment the positon of the return array
   ++zPos;
  }
  return aZ;
}


long *mSort(long *arr, long N){
   // creates a temporary sequence to modify a 2x2 sequence
   int current, index=0;
   long *temp;
   temp = new long[N];

   // performs sort on 2X2 case and then adds to temporary list
   if (N%2==0){
     current = N-1;
   }
   else{
     current = N-4;
   }

   // performs sort on 2X2 case and then adds to temporary
   for (int i = 0; i < current; i=i+2){
     if(arr[i] > arr[i+1]){
       temp[i] = arr[i+1];
       temp[i+1] = arr[i];
     }
     else{
       temp[i] = arr[i];
       temp[i+1] = arr[i+1];
     }
     index = index + 2;
   }

   // if the number sequence is odd we perform a 2x2 sort
   // then compose a final tack on of 3 elements
   if (current < (N-1)){
     if(arr[index] > arr[index+1]){
       if (arr[index+1] > arr[index+2]){
         temp[index] = arr[index+2];
         temp[index+1] = arr[index+1];
         temp[index+2] = arr[index];
       }
       else{
         temp[index] = arr[index+1];
         temp[index+1] = arr[index+2];
         temp[index+2] = arr[index];
       }
     }
     else{
       if (arr[index] > arr[index+2]){
         temp[index] = arr[index+2];
         temp[index+1] = arr[index];
         temp[index+2] = arr[index+1];
       }
       else{
         temp[index] = arr[index+2];
         temp[index+1] = arr[index];
         temp[index+2] = arr[index+1];
       }
     }
   }
   return temp;
}


// works only for even sized sequnces
int main() {
  long *aZ, *aX, *temp, N;
  aX = new long[2];

  // determines the length of the inputed sequence
  std::cout << "How many terms would you like to enter\n";
  std::cin >> N;
  aZ = new long[N];

  std::cout << "Enter your sequence\n";
  // inputting the sorted sequence
  for (int i = 0; i < N; ++i){
    std::cin >> aZ[i];
  }

   // sorts the large sequence into two by two forms
  temp = mSort(aZ, N);
  delete[] aZ; // delete input sequence since temp stores pre-sort
  // printing the sequence

  aX[0] = temp[0];
  aX[1] = temp[1];

  // Merge the smaller sorted sequences of two together
  for (int i=2; i < (N-1); i=i+2){
    long *aY;

    // check to see odd length sequence handling
    if (N%2!=0){
      if (i > (N-4)){
        // otherwise simply create small 2x2 sequences
        aY = new long[3];
        aY[0] = temp[i];
        aY[1] = temp[i+1];
        aY[2] = temp[i+2];

        // successively build out the aX list
        aX = mMerge(aX, aY,i,3,(i+3));
        // delete temporary aY to handle memory
        delete[] aY;
        break;
      }
    }

    // otherwise simply create small 2x2 sequences
    aY = new long[2];
    aY[0] = temp[i];
    aY[1] = temp[i+1];
    // successively build out the aX list
    aX = mMerge(aX, aY,i,2,(i+2));
    // delete temporary aY to handle memory
    delete[] aY;
  }

  // printing the sequence
  std::cout << "Sorted list:\n";
  for (int i = 0; i < N; ++i){
    std::cout << aX[i] << " ";
  }
  delete[] aX;
  std::cout << "\n";
  return 0;
}
