#pragma once
#include <iostream>
#include "Item.h"
using namespace std;

const unsigned int NO_SUCH_ITEM = 999999999;

class ItemManager { 
    int itemCount;
    Item* itemArray;
  public:
    ItemManager ();
    ItemManager (const string& game_name);
    ItemManager (const ItemManager& to_copy);
    ~ItemManager ();
    ItemManager& operator= (const ItemManager& to_copy);
    unsigned int getCount () const;
    int getScore () const;
    void printAtLocation (const Location& location) const;
    void printInventory () const;
    bool isInInventory (char id) const;
    void reset ();
    bool take (char id, const Location& player_location);
    bool leave (char id, const Location& player_location);
  private:
    void load (const string& filename);
    unsigned int find (char id) const;
    void sort ();
    bool isInvariantTrue () const;
};