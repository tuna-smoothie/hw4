//Eric Shong 914868639
#ifndef CODE_H
#define CODE_H

#include <iostream>
#include <string>
#include "Facility.h"

using namespace std;

class Code{
 public:
  Code(string str) : code(str){}
  bool operator()(Facility *f){
    return code == f->code();
  }
 private:
  const string code;
};

#endif //CODE_H
