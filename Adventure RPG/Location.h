#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class Location {
  public:
    unsigned int index;
    Location();
    Location(unsigned int index); // new
    // Location(int row1, int column1);
    bool operator== (const Location& other) const;
    bool isInaccessible() const; // new
};

ostream& operator<< (ostream& out, const Location& location);
