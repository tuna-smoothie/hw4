//
// testSiteNumber.cpp
//
// test the SiteNumber predicate

#include "Facility.h"
#include "Runway.h"
#include "SiteNumber.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int main(int argc, char **argv)
{
  ifstream facilities_file("testFacility1.in");
  string line;
  getline(facilities_file,line);
  Facility *f = new Facility(line);

  cout << f->site_number() << " " << f->code() << " " << f->name() << endl;
  cout << "test if 02187.*A : " << boolalpha
       << SiteNumber<Facility>("02187.*A  ")(f) << endl;
  cout << "test if 04508.*A : " << boolalpha
       << SiteNumber<Facility>("04508.*A  ")(f) << endl;

  ifstream runways_file("testRunway1.in");
  getline(runways_file,line);
  Runway *r = new Runway(line);
  cout << r->site_number() << " " << r->name() << " " << r->length() << endl;
  cout << "test if 02187.*A : " << boolalpha
       << SiteNumber<Runway>("02187.*A  ")(r) << endl;
  cout << "test if 04508.*A : " << boolalpha
       << SiteNumber<Runway>("04508.*A  ")(r) << endl;

  delete f;
}
