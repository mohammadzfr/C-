#include <iostream>
#pragma once
using namespace std;

class Element {
  public:
    string name;
    int score;
    Element* p_next;
    Element();
    ~Element();
  private:
    
};

int getAllocatedElementCount ();
Element* copyLinkedList (const Element* p_head1);
void destroyLinkedList (Element* p_head);

class ScoreTable {
  Element* p_head;
  public:
    //
    // ScoreTable Constructor
    //
    // Purpose: Initialize p_head, a pointer of Element
    // Parameter(s): N/A
    // Precondition(s): p_head is a member in ScoreTable
    // Returns: N/A
    // Side effect: p_head is assigned to nullptr
    //
    ScoreTable ();
    //
    // ScoreTable copy constructor
    //
    // Purpose: copy a linked list to p_head
    // Parameter(s): to_copy: a const Scoretable
    //                variable sent by reference
    // Precondition(s): p_head must exist
    // Returns: N/A
    // Side effect: a linked list is copied to p_head
    //
    ScoreTable (const ScoreTable& to_copy);
    //
    // ScoreTable destructor
    //
    // Purpose: Deallocates p_head's linked list in memory
    // Parameter(s): N/A
    // Precondition(s): p_head must exist
    // Returns: N/A
    // Side effect: the linked list is deallocated
    ~ScoreTable ();
    //
    // operator= assignment operator
    //
    // Purpose: Allows for linked lists to be copied with
    //          the "=" operator
    // Parameter(s): to_copy: a const Scoretable
    //                variable sent by reference
    // Precondition(s): N/A
    // Returns: The copied linked list
    // Side effect: N/A
    //
    ScoreTable& operator= (const ScoreTable& to_copy);
    //
    // print
    //
    // Purpose: prints the requested linked list
    // Parameter(s): N/A
    // Precondition(s): The requested linked list must be initialized
    // Returns: The score and name, if they don't exist,
    //          NULL is printed
    // Side effect: N/A
    //
    void print () const;
    //
    // insert
    //
    // Purpose: Inserts a name and score in a linked list
    // Parameter(s): <1> player_name: a constant string
    //                   sent by reference
    //               <2> score: an integer
    // Precondition(s): linked list must exist
    // Returns: N/A
    // Side effect: linked list now has name and score
    //              inserted in order of score
    //
    void insert (const string& player_name, int score);
  private:
    bool isInvariantTrue() const;
};