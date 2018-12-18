//Eric Shong 914868639
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include "Facility.h"
#include "Code.h"
#include "gcdistance.h"

using namespace std;

int main(int argc, char **argv)
{
  string t1(argv[1]), t2(argv[2]);
  if(t1.length() > 4 || t2.length() > 4){
    cout << "Airport code must be at most 4 characters" << endl;
    return 0;
  }
  if(t1.length() < 4){
    for(int i = 0; i < 4-(int)t1.length(); i++)
      t1 += " ";
  }
  if(t2.length() < 4){
    for(int i = 0; i < 4-(int)t2.length(); i++)
      t2 += " ";
  }

  vector<Facility*> facilities;

  ifstream facilities_file("Facilities.txt");
  string line;
  while(getline(facilities_file, line)){
    Facility* f = new Facility(line);
    facilities.push_back(f);
  }

  vector<Facility*>::iterator it1 = find_if(facilities.begin(), facilities.end(), Code(t1));
  vector<Facility*>::iterator it2 = find_if(facilities.begin(), facilities.end(), Code(t2));

  if(it1 == facilities.end() || it2 == facilities.end()){
    cout << ((it1 == facilities.end()) ? t1 : t2) << " not found" << endl;
  }
  else{
    double d = gcdistance((*it1)->latitude(), (*it1)->longitude(), (*it2)->latitude(), (*it2)->longitude());
    d = (int)d;
    cout << (*it1)->code() << " - " << (*it2)->code() << " " << d << " NM" << endl;
  }

  facilities.clear();
}
