// ---------------------------- node.h ---------------------------------------
// Name and Section: Ryan Harlich, Rio Zhu, Anthony Waddell, Chris Salazar 
//                   CSS 343 B
// Created: February 17, 2018
// Date of Last Modification: February 23, 2018
// ---------------------------------------------------------------------------
// Purpose - A node that contains an item object and a next pointer to another
// node.
// ---------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions: None.
// ---------------------------------------------------------------------------

#ifndef NODE_
#define NODE_

#include "iitem.h"

class Node
{
public:
  // ---------------------------- Node ----------------------------------------
  // Default constructor that sets item pointer and next pointer to NULL.
  // Preconditions: None.
  // Postconditions: m_itemPtr is set to NULL and m_nextNodePtr is set to NULL.
  // --------------------------------------------------------------------------
  Node();

  // ---------------------------- Node ----------------------------------------
  // Default constructor that sets item pointer to the item parameter and next
  // pointer to NULL.
  // Preconditions: Item not be NULL.
  // Postconditions: m_itemPtr is set to itemPtr and m_nextNodePtr is set to 
  // NULL.
  // Parameter: itemPtr - Pointer to an item to store in the node.
  // --------------------------------------------------------------------------
  Node(IItem* itemPtr);

  // ---------------------------- Node ----------------------------------------
  // Default constructor that sets item pointer to the item parameter and next
  // pointer to Node* parameter.
  // Preconditions: Item not be NULL.
  // Postconditions: m_itemPtr is set to itemPtr and m_nextNodePtr is set to 
  // nextNodePtr.
  // Parameter: itemPtr - Pointer to an item to store in the node.
  // nextNodePtr - A pointer to the next node
  // --------------------------------------------------------------------------
  Node(IItem* itemPtr, Node* nextNodePtr);

  // ---------------------------- ~Node ---------------------------------------
  // Destructor that deallocates the m_itemPtr and sets it to NULL.
  // Preconditions: None.
  // Postconditions: m_itemPtr is deallocated and set to NULL.
  // --------------------------------------------------------------------------
  virtual ~Node();

  // ---------------------------- getItemPtr ----------------------------------
  // Gets the item of the node.
  // Preconditions: None.
  // Postconditions: None.
  // Return: Returns item pointer of node.
  // --------------------------------------------------------------------------
  IItem* getItemPtr();

  // ---------------------------- getNextPtr ----------------------------------
  // Gets the next node of the node.
  // Preconditions: None.
  // Postconditions: None.
  // Return: Returns pointer of the next node.
  // --------------------------------------------------------------------------
  Node* getNextPtr();

  // ---------------------------- setNextPtr ----------------------------------
  // Sets the next node pointer.
  // Preconditions: None.
  // Postconditions: None.
  // Parameter: nextPtr - the next node of current node.
  // --------------------------------------------------------------------------
  void setNextPtr(Node* nextPtr);

  // ---------------------------- setNextPtr ----------------------------------
  // Sets the item pointer.
  // Preconditions: None.
  // Postconditions: None.
  // Parameter: itemPtr - the item of the node.
  // --------------------------------------------------------------------------
  void setItemPtr(IItem* itemPtr);

private:
  IItem* m_itemPtr;    // Item pointer to item of node
  Node* m_nextNodePtr; // The next pointer to the next node
};

#endif // !NODE_

