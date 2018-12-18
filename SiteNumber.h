//Eric Shong 914868639
#ifndef HW4_SITENUMBER_H
#define HW4_SITENUMBER_H

#include <string>

using namespace std;

template<class T>
class SiteNumber{
 public:
  SiteNumber(string str) : site(str){}
  bool operator()(T *t){
      return (site == t->site_number());
  }
 private:
  const string site;
};

#endif //HW4_SITENUMBER_H
