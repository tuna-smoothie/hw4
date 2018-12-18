//Eric Shong 914868639
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include "Facility.h"
#include "Runway.h"
#include "Code.h"
#include "SiteNumber.h"

using namespace std;

int main(int argc, char **argv)
{
  string target(argv[1]);
  if(target.length() > 4){
    cout << "Airport code must be at most 4 characters" << endl;
    return 0;
  }
  if(target.length() < 4){
    for(int i = 0; i < 4-(int)target.length(); i++)
      target += " ";
  }

  vector<Facility*> facilities;
  vector<Runway*> runways;

  ifstream facilities_file("Facilities.txt");
  string line;
  while(getline(facilities_file, line)){
    Facility* f = new Facility(line);
    facilities.push_back(f);
  }

  ifstream runways_file("Runways.txt");
  while(getline(runways_file, line)){
    Runway* r = new Runway(line);
    runways.push_back(r);
  }


  vector<Facility*>::iterator fi = find_if(facilities.begin(), facilities.end(), Code(target));

  if(fi == facilities.end()){
    cout << target << " not found" << endl;
  }
  else{
    cout << (*fi)->site_number() << " " << (*fi)->code() << " " << (*fi)->name() << endl;
    vector<Runway*>::iterator ri_end = stable_partition(runways.begin(), runways.end(), SiteNumber<Runway>((*fi)->site_number()));
    vector<Runway*>::iterator ri = runways.begin();
    while(ri != ri_end){
      cout << (*ri)->site_number() << " " << (*ri)->name() << " " << (*ri)->length() << endl;
      ri++;
    }
  }

  facilities.clear();
  runways.clear();

}
