#include <iostream>
#include <cassert>
#include "Game.h"

using namespace std;

Game :: Game (const string& game_name)
     : world(game_name),
       playerLocation(world.getStart()),
       manage(game_name)
{
  assert(isInvariantTrue());
}

bool Game :: isOver () const {
  assert(isInvariantTrue());
  
  if(world.isDeath (playerLocation) || world.isVictory(playerLocation)) {
    return true;
  }
  return false;
}

void Game :: printStartMessage () const {
  assert(isInvariantTrue());
  
  world.printStartMessage();
}

void Game :: printEndMessage () const {
  assert(isInvariantTrue());
  
   world.printEndMessage();
}

void Game :: printDescription () const {
  assert(isInvariantTrue());
  
  world.printDescription(playerLocation);
  manage.printAtLocation(playerLocation);
}

void Game :: printInventory () const {
  assert(isInvariantTrue());
  
  manage.printInventory();
}

void Game :: printScore() const {
  assert(isInvariantTrue());
  
  int score = manage.getScore();
  cout << "In this game you scored " << score << " points." << endl;
}

void Game::moveNorth () {
  assert(isInvariantTrue());
  
  if (world.canGoNorth (playerLocation)) {
    playerLocation = world.getNorth(playerLocation);
    world.printDescription (playerLocation);
    
    manage.printAtLocation(playerLocation);
  }
  else {
    cout << "There is no way to go in that direction.\n";
  }

  assert(isInvariantTrue());
}

void Game :: moveSouth () {
  assert(isInvariantTrue());
  
  if (world.canGoSouth (playerLocation)) {
    playerLocation = world.getSouth(playerLocation);
    world.printDescription (playerLocation);
    
    manage.printAtLocation(playerLocation);
  }
  else {
    cout << "There is no way to go in that direction.\n";
  }

  assert(isInvariantTrue());
}

void Game :: moveEast () {
  assert(isInvariantTrue());
  
  if (world.canGoEast (playerLocation)) {
    playerLocation = world.getEast(playerLocation);
    world.printDescription (playerLocation);
    
    manage.printAtLocation(playerLocation);
  }
  else {
    cout << "There is no way to go in that direction.\n";
  }

  assert(isInvariantTrue());
}

void Game :: moveWest () {
  assert(isInvariantTrue());
  
  if (world.canGoWest (playerLocation)) {
    playerLocation = world.getWest(playerLocation);
    world.printDescription (playerLocation);
    
    manage.printAtLocation(playerLocation);
  }
  else {
    cout << "There is no way to go in that direction.\n";
  }

  assert(isInvariantTrue());
}

void Game :: takeItem (char id) {
  assert(isInvariantTrue());
  
  manage.take(id, playerLocation);

  assert(isInvariantTrue());
}
void Game :: leaveItem (char id) {
  assert(isInvariantTrue());
  
  manage.leave(id, playerLocation);

  assert(isInvariantTrue());
}

void Game :: reset () {
  assert(isInvariantTrue());
  
  manage.reset();
  playerLocation = world.getStart();
  assert(isInvariantTrue());
}
void Game :: updateScoreTable (const string& player_name) {
  player.insert(player_name, manage.getScore());
  cout << endl;
  player.print();
  cout << endl;
}

bool Game :: isInvariantTrue () const {
  if (world.isValid(playerLocation)) {
    return true;
  }
  return false;
}
