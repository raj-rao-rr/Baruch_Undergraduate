#include <iostream>
#include <omp.h>
#include <map>

#include "readFiles.cpp"
#include "timer4300.cpp"

typedef long int myint;


////////////////////////////
// parallel code
////////////////////////////
void paralleF(myint* x, myint n, int& k, int& m){

}


////////////////////////////
// non-parallel code
////////////////////////////
myint* copy(myint* x, myint n){
  myint* arr = new myint[n];
  for (int i = 0; i < n; ++i){
    arr[i] = x[i];
  }
  return arr;
}

// determines what politician a citizen will swap to
int politicianS(std::map<int, int>& arr){
  // determines the maximum value of votes and report the candidate who won
  int winner, votes, max_votes = 0;

  for (int x = 0; x < 10; ++x){
    // votes for a given candidate
    votes = arr.find(x) -> second;
    // tracks the rolling max number of votes and the subsequent winner
    if (votes > max_votes){
      max_votes = votes;
      winner =  x;
    }
    else if (votes == max_votes){
      if (x < winner){
        winner = x;
      }
    }
  }
  return winner;
}

void baseReturn(std::map<int, int>& arr){
  std::map<int, int>::iterator iT;
  // returns the count per every face value of the map dictionary to zero
  for (iT = arr.begin(); iT != arr.end(); ++iT){
    iT -> second = 0;
  }
}

myint* nonparallelF(myint* x, myint n, int k, int m){
  myint* morning = copy(x, n);
  int right, left, candidate, politicalSwap;
  // itterative sequence declartion
  int i, j, l;

  // declaring the voter count per each poltical candidate
  std::pair <int, int> key_ref;
  std::map <int, int> ballots;

  // construct a map to keep track of candidate votes
  for (int i = 0; i < 10; ++i){
    key_ref.first = i;
    key_ref.second = 0;
    ballots.insert(key_ref);
  }

  // itterate through each day
  for (i = 0; i < m; ++i){

    // itterate through each voter to then realize shifts
    for (j = 0; j < n; ++j){

      // wheel construction for neighbors
      for (l = 1; l <= k; ++l){
        right = i + j;
        left = i - j;

        // determines the number of right side neighbors votes
        if (right < n){candidate = morning[right];}
        else {candidate = morning[right%n];} // modulus creates a wrap around


        // determines the number of left side neighbors votes
        if (left < n){ candidate = morning[n+left];} // work backwards from length n
        else{candidate = morning[left];}

        ballots.find(candidate) -> second += 1;
      }

      // we now need to find the new poltical support
      politicalSwap = politicianS(ballots);

      // x arr will be our modified sequence with morning array staying unchanged
      x[j] = politicalSwap;

      // return the ballot map to original values of zero
      baseReturn(ballots);
    }

    // after a morning cycle has passed we updated the new morning with x
    morning = copy(x, n);
  }

  return x;
}


int main(){
  myint *x;
  myint n;

  // read the input from the file
  readSequenceFromFile("hw6_input.txt", &x, &n);

  long k, m;
  std::cout << "Enter the values for k and m\n";
  std::cin >> k >> m;

  Timer4300 tm, vm;

  // runtime for the nonparalel expression
  tm.start();
  nonparallelF(x, n, k, m);
  tm.end();
  std::cout << "The non-parallel function running time is: " << tm.getTime() << "\n";

  delete[] x;
  return 0;
}
