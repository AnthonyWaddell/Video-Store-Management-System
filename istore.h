// ---------------------------- istore.h -------------------------------------
// Name and Section: Ryan Harlich, Rio Zhu, Anthony Waddell, Chris Salazar 
//                   CSS 343 B
// Created: February 17, 2018
// Date of Last Modification: February 23, 2018
// ---------------------------------------------------------------------------
// Purpose - Interface of a store.
// ---------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions: None.
// ---------------------------------------------------------------------------

#ifndef ISTORE_
#define ISTORE_

#include "hash.h"
#include "iperson.h"
#include "linkedlist.h"

#include <fstream> // For ifstream

class IStore
{
public:
  // ---------------------------- IStore --------------------------------------
  // Default constructor that allocates a Linked List that has the stores 
  // inventory. Also, a Hash Table is allocated that stores all the customers.
  // Preconditions: None.
  // Postconditions: An object is created of a LinkedList for stores's 
  // inventory and a Hash for storing customers.
  // --------------------------------------------------------------------------
  IStore();

  // ---------------------------- ~IStore -------------------------------------
  // Destructor that deallocates the inventory of the store, the Linked List.
  // Also, the customer Hash Table is deallocated.
  // Preconditions: None.
  // Postconditions: Inventory Linked List is deallocated and customer Hash
  // Table is deallocated.
  // --------------------------------------------------------------------------
  virtual ~IStore();

  // ---------------------------- buildStore ----------------------------------
  // Virtual method for building a store. Particularly, building its
  // inventory Linked List and building its customer Hash Table.
  // Preconditions: Valid formatted input files.
  // Postconditions: Input files are at the end of file for its streams.
  // Parameters: inputFileCustomers - an input file that contains a list of
  // customers.
  // inputFileInventory - an input file that contains a list of the inventory.
  // --------------------------------------------------------------------------
  virtual void buildStore(std::ifstream& inputFileCustomers, 
    std::ifstream& inputFileInventory) = 0;

  // ---------------------------- runStore ------------------------------------
  // Pure virtual method for running a store.
  // Preconditions: Valid formatted input file.
  // Postconditions: Input file is at the end of file for its stream.
  // Parameters: inputFileCommands - a file that contains a list of commands
  // to execute for a store.
  // --------------------------------------------------------------------------
  virtual void runStore(std::ifstream& inputFileCommands) = 0;

  // ---------------------------- getInventoryLLPtr ---------------------------
  // Gets the Linked List inventory of the IStore.
  // Preconditions: None.
  // Postconditions: None.
  // Return: Returns Linked List object of the inventory list of IStore.
  // --------------------------------------------------------------------------
  LinkedList* getInventoryLLPtr();

  // ---------------------------- getCustomerHashTablePtr ---------------------
  // Gets the Hash Table containing the customers.
  // Preconditions: None.
  // Postconditions: None.
  // Return: Returns Hash Table containing store's customers.
  // --------------------------------------------------------------------------
  Hash* getCustomerHashTablePtr();

protected: //changed this from private so we can access hashtable & linked list
  // ---------------------------- buildCustomers ------------------------------
  // Pure virtual method for building a store's customers.
  // Preconditions: Valid formatted input file.
  // Postconditions: Input file is at the end of file for its stream.
  // Parameters: inputFileCustomers - an input file that contains a list of
  // customers.
  // --------------------------------------------------------------------------
  virtual void buildCustomers(std::ifstream& inputFileCustomers) = 0;

  // ---------------------------- buildInventory ------------------------------
  // Pure virtual method for building a store's inventory.
  // Preconditions: Valid formatted input file.
  // Postconditions: Input file is at the end of file for its streams.
  // Parameters: inputFileInventory - an input file that contains a list of the
  // inventory.
  // --------------------------------------------------------------------------
  virtual void buildInventory(std::ifstream& inputFileInventory) = 0;

  Hash* m_customerHashPtr;      // A Hash Table that contains customers
  LinkedList* m_inventoryLLPtr; // A Linked List containing inventory
};

#endif // !ISTORE_

