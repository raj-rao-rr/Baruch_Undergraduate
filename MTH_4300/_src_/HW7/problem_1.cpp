#include <iostream>

////////////////////////////////////////////
// code provided by imomath.com/bmath
////////////////////////////////////////////

class Frac{
private:
  long num; long den;
public:
  Frac(const long& =0, const long& =1);
  long getNum() const;
  long getDen() const;
  void setNum(const long &);
  void setDen(const long &);
  int operator<(const Frac& ) const;
};

Frac::Frac(const long & n, const long &d){
  num=n;den=d;
  if(den==0){den=1;}
  if(den<0){den*=-1;num*=-1;}
}

long Frac::getNum() const{return num;}
long Frac::getDen() const{return den;}

void Frac::setNum(const long &n){num=n;}

void Frac::setDen(const long &d){
  den=d;
  if(den==0){den=1;}
  if(den<-1){num*=-1;den*=-1;}
}

int Frac::operator<(const Frac & b) const{
  if(num*(b.den)<den*(b.num)){
    return 1;
  }
  return 0;
}

class TNode{
public:
  Frac content;
  TNode* aLeft;
  TNode* aRight;
};

TNode* addTerm(TNode* oldR, const Frac & x){
  if(oldR==NULL){
     TNode* nR;
     nR=new TNode;
     (*nR).aLeft=NULL;
     (*nR).aRight=NULL;
     (*nR).content=x;
     return nR;
   }
  if(x<((*oldR).content)){
    (*oldR).aLeft=addTerm((*oldR).aLeft, x);
  }
  if(((*oldR).content)<x){
    (*oldR).aRight=addTerm((*oldR).aRight, x);
  }
  return oldR;
}

TNode* search(TNode* aR, const Frac& x){
  if(aR==NULL){
    return NULL;
  }
  if(x<((*aR).content)){
    return search((*aR).aLeft, x);
  }
  if( (aR->content) < x){
    return search((*aR).aRight,x);
  }
  return aR;
}

TNode* findMinimum(TNode* aR){
  if(aR==NULL){
    return NULL;
  }
  if((*aR).aLeft==NULL){
    return aR;
  }
  return findMinimum((*aR).aLeft);
}

TNode* deleteMinimum(TNode* aR){
  if(aR==NULL){
    return NULL;
  }
  if((*aR).aLeft==NULL){
    TNode* nRoot;
    nRoot=(*aR).aRight;
    (*aR).aRight=NULL;
    delete aR;
    return nRoot;
  }
  (*aR).aLeft=deleteMinimum((*aR).aLeft);
  return aR;
}

TNode* removeElement(TNode* aR, const Frac & x){
  if(aR==NULL){
    return NULL;
  }
  if(x<((*aR).content)){
    (*aR).aLeft=removeElement((*aR).aLeft, x);
    return aR;
  }
  if(((*aR).content)<x){
    (*aR).aRight=removeElement((*aR).aRight, x);
    return aR;
  }

  // We found out that aR->content is equal to x
  // Check if the right sub-tree is empty
  if((*aR).aRight==NULL){
    TNode* nR=(*aR).aLeft;
    (*aR).aLeft=NULL;
    delete aR;
    return nR;
  }

  // If the right sub-tree is not empty, then pick the smallest
  // member of the right subtree.
  TNode* aMin=findMinimum((*aR).aRight);
  // Swap: aMin->content with aR->content
  Frac tempSwap=(*aMin).content;
  (*aMin).content=(*aR).content;
  (*aR).content=tempSwap;
  // Delete the minimum from the right subtree
  (*aR).aRight=deleteMinimum((*aR).aRight);
  return aR;
}

void printTree(TNode* root){
  if(root!=NULL){
    printTree((*root).aLeft);
    std::cout<<"\t"<<((*root).content).getNum();
    std::cout<<"/"<<((*root).content).getDen();
    printTree((*root).aRight);
  }
}

////////////////////////////////////////////
// code provided by Rajesh Rao (myself)
////////////////////////////////////////////

class SetOfFractions{
private:
  TNode* root;
public:
  SetOfFractions();
  SetOfFractions(const SetOfFractions & );
  SetOfFractions(SetOfFractions &&);
  void operator=(const SetOfFractions &);
  void operator=(SetOfFractions &&);
  long isElement(const Frac &) const;
  long insertInS(const Frac &);
  void printAllFractions() const;
  ~SetOfFractions();
};

SetOfFractions::SetOfFractions(){
  root = NULL;
}

SetOfFractions::SetOfFractions(const SetOfFractions & copyFrom){
  TNode* tempRoot = copyFrom.root;
  root = tempRoot;
}

void SetOfFractions::operator=(const SetOfFractions & copySet){
  if (root != NULL){
   delete[] root;
  }
  root = copySet.root;
}

SetOfFractions::SetOfFractions(SetOfFractions && moveFrom){
  root = moveFrom.root;
}

void SetOfFractions::operator=(SetOfFractions && moveFrom){
  root = moveFrom.root;
}

long SetOfFractions::isElement(const Frac &el) const{
  if (search(root, el) != NULL) {
   return 1;
  }
  return 0;
}

long SetOfFractions::insertInS(const Frac &fr){
  if (search(root, fr) == NULL) {
   root = addTerm(root, fr);
   return 1;
  }
  return 0;
}

void SetOfFractions::printAllFractions() const{
  if(root!=NULL){
   printTree(root);
  }
}

SetOfFractions::~SetOfFractions(){
  if (root != NULL){
  delete[] root;
  }
}

int main(){
  long a,b,c;
  Frac tempFr;
  SetOfFractions setF;
  a=1;
  while(a!=0){
    std::cout<<"Choose one of: 0 (exit), 1 (add), 2 (check for element), ";
    std::cout<<"or 3 (print all)"<<std::endl;
    std::cin>>a;
    if(a==1){
      std::cout<<"Insertion.";
      std::cout<<" What are numerator and denominator? ";
      std::cin>>b>>c;
      tempFr.setNum(b);
      tempFr.setDen(c);
      setF.insertInS(tempFr);
    }
    if(a==2){
      std::cout<<"Checking for element.";
      std::cout<<" What are numerator and denominator? ";
      std::cin>>b>>c;
      tempFr.setNum(b);
      tempFr.setDen(c);
      std::cout<<setF.isElement(tempFr)<<std::endl;
    }
    if(a==3){
      std::cout<<"Printing all fractions."<<std::endl;
      setF.printAllFractions();
      std::cout<<std::endl;
    }
  }
  return 0;
}
