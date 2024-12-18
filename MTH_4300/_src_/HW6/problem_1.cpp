#include <iostream>

class BagOfPoints{
private:
  double *sequenceX;
  double *sequenceY;
  int numPoints;
public:
  BagOfPoints(const int & =0);
  BagOfPoints(const BagOfPoints &);
  BagOfPoints(BagOfPoints &&);
  void operator=(const BagOfPoints &);
  void operator=(BagOfPoints &&);
  ~BagOfPoints();
  double getX(const int &) const;
  double getY(const int &) const;
  int getLength() const;
  void setTerm(const int &, const double &, const double &);
  void setLength(const int &);
};

// Default Constructor //
BagOfPoints::BagOfPoints(const int &k){
  numPoints = k;
  sequenceX = new double[k];
  sequenceY = new double[k];
}

// Accessor Methods //
double BagOfPoints::getX(const int &k) const{return sequenceX[k];}

double BagOfPoints::getY(const int &k) const{return sequenceY[k];}

int BagOfPoints::getLength() const {return numPoints;}

// Mutator Methods //
void BagOfPoints::setTerm(const int &i, const double &x, const double &y){
  sequenceX[i] = x;
  sequenceY[i] = y;
}

void BagOfPoints::setLength(const int &n){
  double *nSequenceX, *nSequenceY;
  nSequenceX = new double[n];
  nSequenceY = new double[n];

  for (int i=0; i < numPoints; ++i){
    nSequenceX[i] = sequenceX[i];
    nSequenceY[i] = sequenceY[i];
  }

  delete[] sequenceX; delete[] sequenceY;
  sequenceX = nSequenceX;
  sequenceY = nSequenceY;
  numPoints = n;
}

// Copy Constructor //
BagOfPoints::BagOfPoints(const BagOfPoints & cF){
  // retrieve the old length and index each position
  int num = cF.getLength();
  for (int i = 0; i < num; ++i){
    sequenceX[i] = cF.getX(i);
    sequenceY[i] = cF.getY(i);
  }
}

// Move Constructor //
BagOfPoints::BagOfPoints(BagOfPoints && mF){
  sequenceX = mF.sequenceX;
  sequenceY = mF.sequenceY;
  mF.sequenceX = NULL;
  mF.sequenceY = NULL;
}

// Copy Assignment //
void BagOfPoints::operator=(const BagOfPoints & cF){
  // retrieve the old length and index each position
  int num = cF.getLength();
  if (&cF != this){
    for (int i = 0; i < num; ++i){
      sequenceX[i] = cF.getX(i);
      sequenceY[i] = cF.getY(i);
    }
  }
}

// Move Assignment //
void BagOfPoints::operator=(BagOfPoints && mF){
  // simply reassign location of sequence
  sequenceX = mF.sequenceX;
  sequenceY = mF.sequenceY;
  mF.sequenceX = NULL;
  mF.sequenceY = NULL;
}

// Deconstructor //
BagOfPoints:: ~BagOfPoints(){
  delete[] sequenceX;
  delete[] sequenceY;
  sequenceX = NULL, sequenceY = NULL;
}

// Reflection Points
BagOfPoints reflectPoints(const BagOfPoints &bag){
  double x, y;
  int N = bag.getLength();
  // construct a new bag of size N from provided bag
  BagOfPoints nBag(N);

  // perform element modification at each index
  for (int i = 0; i < N; ++i){
    x = -1.0*bag.getX(i);
    y = -1.0*bag.getY(i);
    nBag.setTerm(i, x, y);
  }
  return nBag;
}

int main(){
  int n;
  double x,y;
  std::cout << "How many points would you like in the bag \n";
  std::cin >> n;

  BagOfPoints bP(n), bPReflected;

  std::cout << "input an x and y coordinate for each point\n";
  for (int i=0; i < n;++i){
    std::cin >> x >> y;
    bP.setTerm(i, x, y);
  }

  bPReflected = reflectPoints(bP);

  return 0;
}
