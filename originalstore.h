// ---------------------------- originalstore.h ------------------------------
// Name and Section: Ryan Harlich, Rio Zhu, Anthony Waddell, Chris Salazar 
//                   CSS 343 B
// Created: February 17, 2018
// Date of Last Modification: February 23, 2018
// ---------------------------------------------------------------------------
// Purpose - An original store that carriers DVDs for rent.
// ---------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions: None.
// ---------------------------------------------------------------------------

#ifndef ORIGINAL_STORE_
#define ORIGINAL_STORE_

#include "istore.h"

class OriginalStore : public IStore
{
public:
  // ---------------------------- ~OriginalStore ------------------------------
  // An empty virtual destructor for extensibility.
  // Preconditions: None.
  // Postconditions: None.
  // --------------------------------------------------------------------------
  virtual ~OriginalStore();

  // ---------------------------- buildStore ----------------------------------
  // Method for building a store. Particularly, building its
  // inventory Linked List and building its customer Hash Table.
  // Preconditions: Valid formatted input files.
  // Postconditions: Input files are at the end of file for its streams.
  // Parameters: inputFileCustomers - an input file that contains a list of
  // customers.
  // inputFileInventory - an input file that contains a list of the inventory.
  // --------------------------------------------------------------------------
  virtual void buildStore(std::ifstream& inputFileCustomers, std::ifstream& inputFileInventory);

  // ---------------------------- runStore ------------------------------------
  // Method for running a store.
  // Preconditions: Valid formatted input file.
  // Postconditions: Input file is at the end of file for its stream.
  // Parameters: inputFileCommands - a file that contains a list of commands
  // to execute for a store.
  // --------------------------------------------------------------------------
  virtual void runStore(std::ifstream& inputFileCommands);

private:
  // ---------------------------- buildCustomers ------------------------------
  // Method for building a store's customers.
  // Preconditions: Valid formatted input file.
  // Postconditions: Input file is at the end of file for its stream.
  // Parameters: inputFileCustomers - an input file that contains a list of
  // customers.
  // --------------------------------------------------------------------------
  virtual void buildCustomers(std::ifstream& inputFileCustomers);

  // ---------------------------- buildInventory ------------------------------
  // Method for building a store's inventory.
  // Preconditions: Valid formatted input file.
  // Postconditions: Input file is at the end of file for its streams.
  // Parameters: inputFileInventory - an input file that contains a list of the
  // inventory.
  // --------------------------------------------------------------------------
  virtual void buildInventory(std::ifstream& inputFileInventory);
};

#endif // !ORIGINAL_STORE_

