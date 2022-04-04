#include <iostream>
#include "ItemManager.h"
#include <cassert>
#include <fstream>
using namespace std;

ItemManager::ItemManager () {
  itemCount = 0;
  itemArray = new Item[0];
  cout << "test 1" << endl;
  assert(isInvariantTrue());
}

ItemManager::ItemManager (const ItemManager& to_copy) {
  assert(to_copy.isInvariantTrue());
  cout << "test 2" << endl;
  itemCount = to_copy.itemCount;
  itemArray = new Item[itemCount];
  
  for (int i = 0; i < itemCount; i++) {
    itemArray[i] = to_copy.itemArray[i];
  }

  assert(isInvariantTrue());
}

ItemManager::~ItemManager () {
  assert(isInvariantTrue());
  
  delete [] itemArray;
}

ItemManager& ItemManager::operator= (const ItemManager& to_copy) {
  assert(isInvariantTrue());
  if (this != &to_copy) {
    delete [] itemArray;
    
    itemCount = to_copy.itemCount;
    itemArray = new Item[itemCount];
    
    for (int i = 0; i < itemCount; i++) {
      itemArray[i] = to_copy.itemArray[i];
    }
  }
  assert(isInvariantTrue());
  return *this;
}

void ItemManager::load (const string& filename) {
  string clear;
  char id;
  unsigned int temp_location;
  Location start_location;
  int points;
  string world_description, inventory_description;
  
  ifstream loadItems;
  loadItems.open(filename);

  loadItems >> itemCount;
  getline(loadItems, clear);
  
  itemArray = new Item[itemCount];
  for (int i = 0; i < itemCount; i++) {
    getline(loadItems, clear);
    loadItems >> id >> temp_location >> points;
    start_location = Location(temp_location);
    getline(loadItems, clear);
    getline(loadItems, world_description);
    getline(loadItems, inventory_description);
    
    itemArray[i] = Item(id, start_location, points, world_description, inventory_description);
  }

  loadItems.close();
  assert(itemArray != nullptr);
}

void ItemManager::sort() {
  // INSERTION SORT IS USED
  int j, insert_index;
  Item x;

   for (int i = 0; i < itemCount; i++)
   {
      // save the element from position i in the array
      x = itemArray[i];

      // Find the insertion point
      insert_index = 0;
      while ((insert_index < i) && (itemArray[insert_index] < x))
         insert_index++;

      // Shift the elements between here and the last sorted one
      for (j = i; j > insert_index; j--)
         itemArray[j] = itemArray[j-1];

      // Store x at the insertion point
      itemArray[j] = x;
   }
}

ItemManager::ItemManager (const string& game_name) {
  itemArray = nullptr;
  string itemFile = game_name + "_items.txt";

  load(itemFile);
  sort();

  assert(isInvariantTrue());
}

unsigned int ItemManager::getCount () const {
  assert(isInvariantTrue());
  return itemCount;
}

int ItemManager::getScore () const {
  assert(isInvariantTrue());
  
  int score = 0;
  for (int i = 0; i < itemCount; i++) {
    score += itemArray[i].getPlayerPoints();
  }
  return score;
}

void ItemManager::printAtLocation (const Location& location) const {
  assert(isInvariantTrue());
  
  for (int i = 0; i < itemCount; i++) {
    if (itemArray[i].isAtLocation(location)) {
      itemArray[i].printDescription();
    }
  }
}
void ItemManager::printInventory () const {
  assert(isInvariantTrue());
  
  for (int i = 0; i < itemCount; i++) {
    if (itemArray[i].isInInventory()) {
      itemArray[i].printDescription();
    }
  }
}
bool ItemManager::isInInventory (char id) const {
  assert(isInvariantTrue());
  
  if (find(id) != NO_SUCH_ITEM) {
    if (isInInventory(id)) {
      return true;
    }
  }
  
  return false;
}
void ItemManager::reset () {
  assert(isInvariantTrue());
  
  for (int i = 0; i < itemCount; i++) {
    itemArray[i].reset();
  }
  

  assert(isInvariantTrue());
}

bool ItemManager::take (char id, const Location& player_location) {
  assert(isInvariantTrue());
  
  for (int i = 0; i < itemCount; i++) {

    if (id == itemArray[i].getId()) 
    {

      if (itemArray[i].isAtLocation(player_location)) 
      {
        cout << "Found it!\n";
        itemArray[i].moveToInventory();
        
        assert(isInvariantTrue());
        return true;
      }
      else 
      {
        cout << "Item already in inventory\n";

        assert(isInvariantTrue());
        return false;
      }
    }
    if (i == itemCount - 1) {
      cout << "Invalid Item\n";
      
    }
  }
  assert(isInvariantTrue());
  return false;
}

bool ItemManager::leave (char id, const Location& player_location) {
  assert(isInvariantTrue());
  
  for (int i = 0; i < itemCount; i++) {
    if (id == itemArray[i].getId()) {
  
      if (itemArray[i].isInInventory()) {
        cout << "Item dropped!\n";
        itemArray[i].moveToLocation(player_location);

        assert(isInvariantTrue());
        return true;
      }
      else {
        cout << "Item not in inventory\n";

        assert(isInvariantTrue());
        return false;
      }
    }
    if (i == itemCount - 1) {
      cout << "Invalid Item\n";
      
    }
  }
  assert(isInvariantTrue());
  return false;
}

unsigned int ItemManager::find (char id) const {
  int low = 0;
  int high = itemCount - 1;
  while (low <= high) 
    {
      int mid = (low + high) / 2;
      if (id == itemArray[mid].getId()) {
      return mid;
      } 
      else if (id < itemArray[mid].getId()) {
       high = mid - 1;
      } 
      else {
      low = mid + 1;
      } 
    }
    return NO_SUCH_ITEM;
}

bool ItemManager::isInvariantTrue () const {
  if (itemArray == nullptr) {
    return false;
  }
  for (int i = 0; i < itemCount; i++) {
    if (!(itemArray[i].isInitialized())) {
      return false;
    }
  }
  for (int i = 0; i < itemCount - 1; i++) {
    if(itemArray[i + 1] < itemArray[i]) {
      return false;
    }
  }
  
  return true;
}