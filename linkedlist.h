// ---------------------------- linkedlist.h ---------------------------------
// Name and Section: Ryan Harlich, Rio Zhu, Anthony Waddell, Chris Salazar 
//                   CSS 343 B
// Created: February 17, 2018
// Date of Last Modification: February 23, 2018
// ---------------------------------------------------------------------------
// Purpose - A Linked List that inserts items into the list sorted and can
// also remove one copy of the item from the Linked List.
// ---------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions: A Linked
// List.
// ---------------------------------------------------------------------------

#ifndef LINKED_LIST_
#define LINKED_LIST_

#include "node.h"

class LinkedList
{
public:
  // ---------------------------- LinkedList ----------------------------------
  // Default constructor that sets the head pointer to NULL.
  // Preconditions: None.
  // Postconditions: Head pointer is set to NULL.
  // --------------------------------------------------------------------------
  LinkedList();

  // ---------------------------- ~LinkedList ---------------------------------
  // Destructor that deallocates all nodes in Linked List and deallocates all
  // items in Linked List.
  // Preconditions: None.
  // Postconditions: Linked List nodes are deallocated along with its items,
  // which are deallocated.
  // --------------------------------------------------------------------------
  virtual ~LinkedList();

  // ---------------------------- removeFront ---------------------------------
  // Deallocates front node and its item and sets the head pointer to its next.
  // Preconditions: None.
  // Postconditions: Head pointer points to its next and what was the front
  // of the Linked List, that node is deallocated along with its item.
  // Return: Returns true if able to remove.
  // --------------------------------------------------------------------------
  bool removeFront();

  // ---------------------------- isEmpty -------------------------------------
  // Returns whether the list is empty or not. True for is empty.
  // Preconditions: None.
  // Postconditions: None.
  // Return: Returns true if Linked List is empty, false otherwise.
  // --------------------------------------------------------------------------
  bool isEmpty();

  // ---------------------------- displayAll ----------------------------------
  // Displays the entire contents of the Linked List line by line.
  // Preconditions: None.
  // Postconditions: Out stream contains all contents of Linked List.
  // Parameter: outStream - the out stream for displaying contents.
  // --------------------------------------------------------------------------
  void displayAll(std::ostream& outStream);

  // ---------------------------- insertSorted --------------------------------
  // Inserts a new item to the Linked List in sorted order. Also, increases
  // stock count of item if same item.
  // Preconditions: Item is not NULL and duplicate is set to false initially.
  // Postconditions: Linked List contains newly added item; however, if
  // duplicate client will have to deallocate the IItem pointer that was passed
  // in as an argument.
  // Parameter: itemPtr - the item to be inserted into the Linked List.
  // duplicate - whether the item was a duplicate in which case client will
  // have to deallocate IItem pointer if duplicate becomes true. Needs to be
  // initially false before method is executed.
  // Return: Returns true if successfully inserted, false otherwise.
  // --------------------------------------------------------------------------
  bool insertSorted(IItem* itemPtr, bool& duplicate);

  // ---------------------------- removeOneCopy -------------------------------
  // Removes stock count from all copies that are the same movie. Then, the
  // IItem pointer stock is increased by one.
  // Preconditions: Item is not NULL and outOfStock is initiated to false.
  // Postconditions: This linked list will have one copy removed from all of 
  // the same movie and the itemLookUpKey will have its stock increased by one.
  // Parameter: itemLookUpKeyPtr - an item to find and remove one stock. Its
  // stock is then increased to one.
  // outOfStock - Initially false becomes true if item is out of stock.
  // Return: Returns true if one stock was removed.
  // --------------------------------------------------------------------------
  bool removeOneCopy(IItem* itemLookUpKeyPtr, bool& outOfStock);

private:
  Node* m_headPtr; // Head pointer of Linked List
};

#endif // !LINKED_LIST_