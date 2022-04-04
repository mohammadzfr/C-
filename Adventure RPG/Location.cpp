#include <iostream>
#include <iomanip>
#include "Location.h"
using namespace std;

Location::Location() {
  index = 0;
}

Location::Location(unsigned int index1) {
  index = index1;
}

bool Location::operator== (const Location& other) const {
  if (index == other.index)
    return true;
  
  return false;
}

bool Location::isInaccessible() const {
  if (index == 0) {
    return true;
  }

  return false;
}
ostream& operator<< (ostream& out, const Location& location) {
  if (!location.isInaccessible()) {
    out << "(node = " << location.index << ")";
  }
  else {
    out << "(node = INACCESSIBLE)";
  }
  return out;
}