#include <string>
#include <iostream>
#include <fstream>
#include <cassert>

using namespace std;
#include "World.h"

World::World (const string& game_name) {
  description_count = 0;
  loadNodes(game_name + "_nodes.txt");
  loadDescriptions(game_name + "_text.txt");
  assert(isInvariantTrue());
}

void World::loadNodes (const string& filename) {
  int i_obstruct;
  char node_type, c_obstruct;
  ifstream LoadNodes;
  LoadNodes.open(filename.c_str());

  if (!LoadNodes)
  {
    cout << "Error!";
    return;
  }
  LoadNodes >> node_count;
  LoadNodes >> start_node;
  LoadNodes >> victory_node;
  LoadNodes >> start_message;
  LoadNodes >> end_message;
  for (int i = 0; i < node_count; i++) 
  {
    LoadNodes >> node_type;
    LoadNodes >> nodes[i].description;
    LoadNodes >> nodes[i].north;
    LoadNodes >> nodes[i].south;
    LoadNodes >> nodes[i].east;
    LoadNodes >> nodes[i].west;
    nodes[i].is_death = false;
    
    if (node_type == 'D') {
      nodes[i].is_death = true;
    }
    else if (node_type == 'O') {
      LoadNodes >> c_obstruct;
      LoadNodes >> i_obstruct;
      LoadNodes >> i_obstruct;
    }
  }

  LoadNodes.close();
}

void World::loadDescriptions (const string& filename) {
  string tempDesc;
  ifstream LoadDescriptions;
  LoadDescriptions.open(filename);

  if (!LoadDescriptions)
  {
    cout << "Error!";
    return;
  }
  
  description_count = 0;
	LoadDescriptions >> description_count;
	string line;
	getline(LoadDescriptions, line);

	// read blank line
	getline(LoadDescriptions, line);

	// read descriptions
	for(unsigned int d = 0; d < description_count; d++)
	{
		descriptions[d] = "";

		getline(LoadDescriptions, line);
		while(line != "")
		{
			descriptions[d] += line + "\n";
			getline(LoadDescriptions, line);
		}
	}
  
  LoadDescriptions.close();
}



void World::debugPrint () const { 
  cout << "Number of nodes: " << node_count << endl;
  cout << "Start node: " << start_node << endl;
  cout << "Victory node: " << victory_node << endl;
  cout << "Start message: " << start_message << endl;
  cout << "End message: " << end_message << endl;
  
  for (int i = 0; i < node_count; i++) 
  {
    nodes[i].debugPrint();
  }
  
  cout << description_count;
  for (int i = 0; i < description_count; i++) {
    cout << descriptions[i] << endl << endl;
  }
}

bool World::isValid (const Location& location) const {
  assert(isInvariantTrue());
  if (location.index < node_count) 
    return true;

  else 
    return false;     
    
}

bool World::canGoNorth (const Location& location1) const {
  assert(isInvariantTrue());
  assert(isValid(location1));
  Location loc = nodes[location1.index].getNorth();
  
  if (loc.isInaccessible()) {
    return false;
  }
  if(!isValid(loc))
    return false;

  return true;

}

bool World::canGoSouth (const Location& location1) const {
  assert(isInvariantTrue());
  assert(isValid(location1));
  Location loc = nodes[location1.index].getSouth(); 
  
  if (loc.isInaccessible()) {
    return false;
  }
  if(!isValid(loc))
    return false;

  return true;

}

bool World::canGoEast (const Location& location1) const {
  assert(isInvariantTrue());
  assert(isValid(location1));
  Location loc = nodes[location1.index].getEast(); 
  
  if (loc.isInaccessible()) {
    return false;
  }
  if(!isValid(loc))
    return false;

  return true;

}

bool World::canGoWest (const Location& location1) const {
  assert(isInvariantTrue());
  assert(isValid(location1));
  Location loc = nodes[location1.index].getWest(); 
  
  if (loc.isInaccessible()) {
    return false;
  }
  if(!isValid(loc))
    return false;

  return true;

}

Location World::getNorth (const Location& location1) const {
  assert(isInvariantTrue());
  assert(canGoNorth(location1));
  Location loc = nodes[location1.index].getNorth();
  return loc;
  
}
    
Location World::getSouth (const Location& location1) const {
  assert(isInvariantTrue());
  assert(canGoSouth(location1));
  Location loc = nodes[location1.index].getSouth();
  return loc;
}
    
Location World::getEast  (const Location& location1) const{
  assert(isInvariantTrue());
  assert(canGoEast(location1));
  Location loc = nodes[location1.index].getEast();
  return loc;
}
    
Location World::getWest  (const Location& location1) const {
  assert(isInvariantTrue());
  assert(canGoWest(location1));
  Location loc = nodes[location1.index].getWest();
  return loc;
}

bool World::isDeath (const Location& location) const {
  assert(isInvariantTrue());
  assert(isValid(location));
  
  if (nodes[location.index].isDeath())
    return true;

  else
    return false;

}

bool World::isVictory (const Location& location) const {
  assert(isInvariantTrue());
  assert(isValid(location));
  
  if (location.index == victory_node)
    return true;

  else
    return false;

}

Location World::getStart () const {
  assert(isInvariantTrue());
  
  return start_node;
  
}

void World::printDescription (const Location& location) const {
  assert(isInvariantTrue());
  unsigned int index = nodes[location.index].description;
  
  cout << descriptions[index];
    
}

void World::printStartMessage () const {
  assert(isInvariantTrue());
  cout << descriptions[start_message];
}

void World::printEndMessage () const {
  assert(isInvariantTrue());
  cout << descriptions[end_message];
}

bool World::isInvariantTrue () const {
  
  if (description_count <= MAX_DESCRIPTION_COUNT) {
    for (int d = 0; d < description_count; d++) {
      if (descriptions[d] == "") {
        return false;
      }
    }
    for (int i = 0; i < node_count; i++) {
      if (!(nodes[i].description < description_count)) {
        return false;
      }
    }
  }
  else {
    return false;
  }
  if (node_count <= MAX_NODE_COUNT) {
    if (!(start_node < node_count && victory_node < node_count)) {
      return false;
      if (!(start_message < node_count && end_message < node_count)) {
        return false;
      }
    }
  }
  else {
    return false;
  }
  
  return true;
}