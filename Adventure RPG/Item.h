#pragma once
#include <iostream>
#include <string>
#include "Location.h"
using namespace std;

const char ID_NOT_INITIALIZED = '\0';
// const int ITEM_COUNT = 9;

class Item {
  private:
    char id;
    Location startLocation, currentLocation;
    bool inInventory;
    int points;
    string groundDescription, inventoryDescription;

    bool isInvariantValue () const;  // new in A3
  public:
    Item ();
    Item (char id1,
          const Location& location,
          int points1,
          const string& world_description1,
          const string& inventory_description1);
    void debugPrint () const;
    bool isInitialized () const;  // new in A3
    char getId () const;
    bool isInInventory () const;
    bool isAtLocation (const Location& location) const;
    int getPlayerPoints () const;
    void printDescription () const;
    bool operator< (const Item& other) const;  // new in A3
    void reset ();
    void moveToInventory ();
    void moveToLocation (const Location& location);
  
};