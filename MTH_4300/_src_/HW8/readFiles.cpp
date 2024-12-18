// readFiles.cpp
// code is copied from imomath.com/bmath

// code to read numerical data from a file
#include <iostream>
#include <fstream>

typedef long int myint;

myint getNextInteger(char * text, std::streampos size, std::streampos *pos){
  myint current=0;
  myint mult=1;
  std::string specCharacters="-09";

  while ((*pos<size) &&(text[*pos]!=specCharacters[0])&&(( text[*pos]<specCharacters[1])||(text[*pos]>specCharacters[2]))){
    *pos= (*pos)+((std::streampos)1);
  }

  if(text[*pos]==specCharacters[0]){
    mult=-1;
    *pos= (*pos)+((std::streampos)1);
  }

  while ((*pos<size) &&(( text[*pos]>=specCharacters[1])&&(text[*pos]<=specCharacters[2]))){
    current= 10 * current;
    current+= (int)(text[*pos]-specCharacters[1]);
    *pos=*pos+((std::streampos)1);
  }

  current=current*mult;
  return current;
}

void readSequenceFromFile(std::string filename, myint** sequencePointer, myint *length){
  srand((unsigned)time(0));
  std::streampos size; std::streampos *position;
  position=new std::streampos;
  *position=0;
  char * memblock;
  std::ifstream ifile(filename,std::ios::in|std::ios:: binary|std::ios:: ate);

  if (ifile.is_open()){
    size = ifile.tellg();
    memblock = new char [size];
    ifile.seekg (0, std::ios:: beg);
    ifile.read (memblock, size);
    ifile.close();
    *length=getNextInteger(memblock,size,position);
    *sequencePointer=new myint[*length];
    myint i=0;myint cNum=0;
    while((i<*length)&&(cNum!=-9)){
      cNum=getNextInteger(memblock,size,position);

      if(cNum!=-9){
        (*sequencePointer)[i]=cNum;
        ++i;
      }
    }
    while(i<(*length)){
      (*sequencePointer)[i]=0;
      ++i;
    }
    delete[] memblock;
  }
  delete position;
}

void printToFile(std::string filename, myint *s, myint l){
  std::ofstream mfile;
  mfile.open(filename);
  for(myint i=0;i<l;++i){
    mfile<<s[i]<<", ";
  }
  mfile<<std::endl;
  mfile.close();
}
