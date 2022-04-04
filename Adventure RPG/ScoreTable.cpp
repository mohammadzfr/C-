#include "ScoreTable.h"
#include <iostream>
#include <cassert>

static int elementCount = 0;

int getAllocatedElementCount () {
  return elementCount;
}

Element::Element() 
  :name(),
  score(0),
  p_next(nullptr)
{
  elementCount++;
}

Element::~Element() {
  elementCount--;
}

Element* copyLinkedList (const Element* p_head1) {
  if (p_head1 == nullptr)
    return nullptr;

  Element *pHead2 = new Element;
  pHead2->name = p_head1->name;
  pHead2->score = p_head1->score;
  
  const Element *p1 = p_head1;
  Element       *p2 = pHead2;

  while (p1->p_next != nullptr)
  {
    p2->p_next = new Element;

    p1 = p1->p_next;
    p2 = p2->p_next;

    p2->name = p1->name;
    p2->score = p1->score;
  }

  // set the end of the new linked list to nullptr
  p2->p_next = nullptr;

  return pHead2;
}

void destroyLinkedList (Element* p_head) {
  
  Element *pCurrent = nullptr;
  Element *pNext = p_head;
  while (pNext != nullptr) 
  {
    pCurrent = pNext;
    pNext = pCurrent->p_next;
    delete pCurrent;
  }
};

ScoreTable :: ScoreTable ()
  :p_head(nullptr)
{
  assert(isInvariantTrue());
}

void ScoreTable :: print () const{
  assert(isInvariantTrue());
  
  Element* p1 = p_head;
  cout << "Scores:" << endl;
  
  if (p1 == nullptr) {
    cout << "Value is NULL" << endl;
  }
    
    while (p1 != nullptr)  // still Elements to copy
  {
    cout << p1->score << "\t" << p1->name << endl;
    p1 = p1->p_next;
  }
  
  
}

void ScoreTable :: insert (const string& player_name, int score) {
  assert(isInvariantTrue());
  
  Element* pPrev = nullptr;
  Element* pCurrent = p_head;
  while (pCurrent != nullptr && pCurrent->score > score) 
  {
    pPrev = pCurrent;
    pCurrent = pCurrent->p_next;
  }

  Element* p_insert = new Element;
  p_insert->name = player_name;
  p_insert->score = score;
  
  if (pPrev == nullptr) 
  {
    p_insert->p_next = p_head;
    p_head = p_insert;
  }
  else
  {
    p_insert->p_next = pPrev->p_next;
    pPrev->p_next = p_insert;
  }
  assert(isInvariantTrue());
}

ScoreTable :: ScoreTable (const ScoreTable& to_copy) {
  assert(to_copy.isInvariantTrue());
  
  p_head = copyLinkedList(to_copy.p_head);
  
  assert(isInvariantTrue());
}

ScoreTable :: ~ScoreTable () {
  destroyLinkedList(p_head);
}

ScoreTable& ScoreTable :: operator= (const ScoreTable& to_copy) {
  assert(to_copy.isInvariantTrue());
  assert(isInvariantTrue());
  
  if (&to_copy != this) 
  {
    destroyLinkedList(p_head);
    p_head = copyLinkedList(to_copy.p_head);
  }
  assert(isInvariantTrue());
  
  return *this;
}

bool ScoreTable :: isInvariantTrue() const {
  Element* pCurrent = new Element;
  pCurrent = p_head;
  if (pCurrent == nullptr) {
    return true;
  }
  while (pCurrent->p_next != nullptr) {
    if (pCurrent->score < pCurrent->p_next->score) {
      return false;
    }
    pCurrent = pCurrent->p_next;
  }
  return true;
}