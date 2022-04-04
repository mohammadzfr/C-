#pragma once
#include "ItemManager.h"
#include "World.h"
#include "ScoreTable.h"

class Game {
  public:
    World world;
    Location playerLocation;
    ItemManager manage;
    ScoreTable player;

    Game (const string& game_name);
    bool isOver () const;
    void printStartMessage () const;
    void printEndMessage () const;
    void printDescription () const;
    void printInventory () const;
    void printScore () const;
    void reset ();
    void moveNorth ();
    void moveSouth ();
    void moveEast ();
    void moveWest ();
    void takeItem (char id);
    void leaveItem (char id);
    void updateScoreTable (const string& player_name);
  private:
    bool isInvariantTrue () const;
};