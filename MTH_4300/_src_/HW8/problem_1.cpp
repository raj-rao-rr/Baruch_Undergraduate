#include <iostream>
#include <algorithm>
#include <omp.h>
#include <map>

#include "readFiles.cpp"
#include "timer4300.cpp"

typedef long int myint;


////////////////////////////
// parallel code
////////////////////////////
void parallelF(myint* x, myint n){
  long m;

  // define the number optimal threats to use
  #pragma omp parallel
  {
    if(omp_get_thread_num() == 0){
      m = omp_get_num_threads();
    }
  }

  // determines the maximum value of votes and report the candidate who won
  int winner, votes, max_votes = 0;

  #pragma omp parallel num_threads(m)
  {
    // inside parallel cide within cores
    long myId = omp_get_thread_num();
    long j = myId;
    // iterate through each politicians and count the total votes
    while (j < 10){
      votes = std::count(x, x+n, j);
      // check which politician recieved the most votes and updates winner
      if (votes > max_votes){
        max_votes = votes;
        winner =  j;
      }
      j += m;
    }
  }

  std::cout << "The winner of the election is " << winner << " with " << max_votes << " votes\n";
}


////////////////////////////
// non-parallel code
////////////////////////////
void nonparallelF(myint* x, myint n){
  int candidate;

  // declaring the voter count per each poltical candidate
  std::pair <int, int> key_ref;
  std::map <int, int> ballots;

  // construct a map to keep track of candidate votes
  for (int i = 0; i < 10; ++i){
    key_ref.first = i; // politician
    key_ref.second = 0; // initialize votes to zero
    ballots.insert(key_ref);
  }

  // iterates through the entire x sequence and counts the total votes
  for (int j = 0; j < n; ++j){
    candidate = x[j];
    ballots.find(candidate) -> second += 1; // adds one vote per perosn
  }

  // determines the maximum value of votes and report the candidate who won
  int winner, votes, max_votes = 0;

  for (int x = 0; x < 10; ++x){
    // votes for a given candidate
    votes = ballots.find(x) -> second;
    // output each politicians total votes
    std::cout << "Candidate " << x << " recieved " << votes << " votes\n";
    // tracks the rolling max number of votes and the subsequent winner
    if (votes > max_votes){
      max_votes = votes;
      winner =  x;
    }
  }

  std::cout << "\nThe winner of the election is " << winner << " with " << max_votes << " votes\n";
}


int main(){
  myint *x;
  myint n;

  // read the input from the file
  readSequenceFromFile("hw6_input.txt", &x, &n);

  Timer4300 tm, vm;

  // runtime for the nonparalel expression
  tm.start();
  nonparallelF(x, n);
  tm.end();
  std::cout << "The non-parallel function running time is: " << tm.getTime() << "\n";

  std::cout << "---------------------------------------\n";

  // runtime for the paralel expression
  vm.start();
  parallelF(x, n);
  vm.end();
  std::cout << "The parallel function running time is: " << vm.getTime() << "\n";

  delete[] x;
  return 0;
}
