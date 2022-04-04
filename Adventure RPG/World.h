#pragma once
#include "Location.h"
#include "Node.h"
#include <string>
using namespace std;



const Location NO_SUCH_VALUE = Location(-1);

unsigned int const MAX_DESCRIPTION_COUNT = 1000;
unsigned int const MAX_NODE_COUNT = 1000;

class World {
private:

  void loadNodes(const string &filename);
  void loadDescriptions(const string &filename);
  bool isInvariantTrue() const; // new in A3

  Node nodes[MAX_NODE_COUNT];
  string descriptions[MAX_DESCRIPTION_COUNT];
  unsigned int description_count = 0;
  unsigned int node_count = 0;
  unsigned int start_node;
  unsigned int victory_node;
  unsigned int start_message;
  unsigned int end_message;
public:
  //
  // Constructor: World
  //
  // Purpose: Initialize the game world for the player
  // Parameter(s):
  //  <1> game_name: The prefix of the game files
  //                 sent by reference as a constant string
  // Precondition(s): game_name != ""
  //                  (technically can be but it won't match up with the files)
  //                   _text.txt and _grid.txt files have to exist
  // Returns: N/A
  // Side effect: description_count set to 0,
  //              loads the game nodes from grid file,
  //              loads the descriptions from text file,
  //

  World(const string &game_name);
  void debugPrint() const;
  bool isValid(const Location &location) const;
  bool isDeath(const Location &location) const;
  bool isVictory(const Location &location) const;
  bool canGoNorth(const Location &location) const;
  bool canGoSouth(const Location &location) const;
  bool canGoEast(const Location &location) const;
  bool canGoWest(const Location &location) const;

  //
  // getNorth
  //
  // Purpose: moves the player's position one node to the north
  // Parameter(s):
  //  <1> location: The current location of the player
  //                sent by reference as a constant with the location type
  // Precondition(s): playerLocation != {} (nothing) || playerLocation !=
  // NO_SUCH_VALUE
  //                  (every other precondition is included in asserts)
  // Returns: loc (the player location one node to the north)
  // Side effect: N/A
  //

  Location getNorth(const Location &location) const; // new in A3
  Location getSouth(const Location &location) const; // new in A3
  Location getEast(const Location &location) const;  // new in A3
  Location getWest(const Location &location) const;  // new in A3
  Location getStart() const;
  void printStartMessage() const;
  void printEndMessage() const;
  void printDescription(const Location &location) const;
};