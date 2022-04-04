#include <iostream>
#include <string>
#include <cassert>
#include "Item.h"
using namespace std;

Item::Item ()
  : id(ID_NOT_INITIALIZED),
    inInventory(false),
    startLocation(),
	  currentLocation(),
    points(0),
    groundDescription("[Item not initialized]"),
    inventoryDescription("[Item not initialized]")
{
  assert(isInvariantValue());
}

Item::Item (char id1,
            const Location& location,
            int points1,
            const string& world_description1,
            const string& inventory_description1) 
  : id(id1),
    inInventory(false),
    startLocation(location),
    currentLocation(location),
    points(points1),
    groundDescription(world_description1),
    inventoryDescription(inventory_description1)
    
{

  assert(id1 != ID_NOT_INITIALIZED);
  assert(world_description1 != "" && inventory_description1 != "");
  assert(isInvariantValue());
  
}

void Item::debugPrint () const {
  cout << "id:             \t\'" << id << "\'" << endl;
  cout << "startLocation:      "; operator<<(cout, startLocation) << endl;
  cout << "currentLocation:    "; operator<<(cout, currentLocation) << endl;
	cout << "is_in_inventory:\t" << inInventory << endl;
	cout << "points:         \t" << points << endl;
	cout << "world_description:    \t\"" << groundDescription << "\"" << endl;
	cout << "inventory_description:\t\"" << inventoryDescription << "\"" << endl;
  
}

bool Item::isInitialized () const {
  assert(isInvariantValue());
  
  if (id == ID_NOT_INITIALIZED)
    return false;

  return true;
}

char Item::getId () const {
  assert(isInvariantValue());
  
  return id;
}

bool Item::isInInventory () const {
  assert(isInvariantValue());
  
  return inInventory;
}

bool Item::isAtLocation (const Location& location1) const {
  assert(isInvariantValue());
  
  if (inInventory) {
    return false;
  }
  else if (!(currentLocation == location1)) {
    return false;
  }
  
  return true;
}

int Item::getPlayerPoints () const {
  assert(isInvariantValue());
  
  if (inInventory) {
    return points;
  }
  else {
    return 0;
  }
}

void Item::printDescription () const {
  assert(isInvariantValue());
  
  if (inInventory) {
    cout << inventoryDescription << endl;
    
  }
  else {
    cout << groundDescription << endl;
  }
  return;
}

void Item::reset () {
  assert(isInvariantValue());
  
  currentLocation = startLocation;
  inInventory = false;

  assert(isInvariantValue());
}

void Item::moveToInventory () {
  assert(isInvariantValue());
  
  inInventory = true;

  assert(isInvariantValue());
}

void Item::moveToLocation (const Location& location) {
  assert(isInvariantValue());
  
  currentLocation = location;
  inInventory = false;

  assert(isInvariantValue());
}

bool Item::operator< (const Item& other) const {
  assert(isInvariantValue());
  
  if (id < other.id)
    return true;

  return false;
}

bool Item::isInvariantValue () const {
  
  
  if (groundDescription != "" || inventoryDescription != "") {
    return true;
  }
    
  
  return false;
}