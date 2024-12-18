// timer4300.cpp
// code is copied from imomath.com/bmath

// code is to be used in tracking runtime performance of a given program
#include <iostream>
#include <chrono>

class Timer4300{
private:
  long timerStart;
  long timerEnd;
  long timerInProgress;
public:
  Timer4300(const long & =0);
  void start();
  void end();
  double getTime();
};

Timer4300::Timer4300(const long & _inProgress){
  timerInProgress=_inProgress;
  if(timerInProgress==1){
    timerStart=std::chrono::high_resolution_clock::now().time_since_epoch().count();
  }
}
void Timer4300::start(){
  timerInProgress=1;
  timerStart=std::chrono::high_resolution_clock::now().time_since_epoch().count();
}
void Timer4300::end(){
  timerInProgress=2;
  timerEnd=std::chrono::high_resolution_clock::now().time_since_epoch().count();
}
double Timer4300::getTime(){
  if(timerInProgress!=2){
    return -1.0;
  }
  double fR= double(timerEnd)-double(timerStart);
  fR/= 1000000.0;
  return fR;
}
