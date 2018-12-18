//Eric Shong 914868639
#include <string>
#include "Facility.h"
#include "gcdistance.cpp"

using namespace std;

Facility::Facility(string s) : site_number_(s.substr(0, 10)),
                               type_(s.substr(11,13)),
                               code_(s.substr(24, 4)),
                               name_(s.substr(130, 50)),
                               latitude_(this->convert_latitude(s.substr(535, 12))),
                               longitude_(this->convert_longitude(s.substr(562, 12))){
}

string Facility::site_number() const {
  return site_number_;
}

string Facility::type() const {
  return type_;
}

string Facility::code() const {
  return code_;
}

string Facility::name() const {
  return name_;
}

double Facility::latitude() const {
  return latitude_;
}

double Facility::longitude() const {
  return longitude_;
}

double Facility::distance(double lat, double lon) const {
  return gcdistance(latitude_, longitude_, lat, lon);
}

double Facility::convert_latitude(std::string s) const {
  double d = stod(s.substr(0, s.length()-1)) / 3600;
  d = (s.at(s.length()-1) == 'N') ? d : -d;
  return d;
}

double Facility::convert_longitude(std::string s) const {
  double d = stod(s.substr(0, s.length()-1)) / 3600;
  d = (s.at(s.length()-1) == 'E') ? d : -d;
  return d;
}