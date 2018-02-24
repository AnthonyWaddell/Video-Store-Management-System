// ---------------------------- inventory.h ----------------------------------
// Name and Section: Ryan Harlich, Rio Zhu, Anthony Waddell, Chris Salazar 
//                   CSS 343 B
// Created: February 17, 2018
// Date of Last Modification: February 23, 2018
// ---------------------------------------------------------------------------
// Purpose - Processes the inventory action.
// ---------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions: None.
// ---------------------------------------------------------------------------

#ifndef INVENTORY_
#define INVENTORY_

#include "iaction.h"

class Inventory : public IAction
{
public:
  // ---------------------------- ~Inventory ----------------------------------
  // An empty virtual destructor for extensibility.
  // Preconditions: None.
  // Postconditions: None.
  // --------------------------------------------------------------------------
  virtual ~Inventory();

  // ---------------------------- processAction -------------------------------
  // Processes the inventory action reading what to do from a input file.
  // Preconditions: A valid IStore object. Correctly formatted input file line.
  // Postconditions: Input file ifstream will be at the end of the line.
  // Prints to the screen the stores inventory.
  // Parameter: inputFile - A input file with lines of properly formatted
  // commands.
  // store - An IStore object.
  // Return: Returns true if inventory displaying was successful, and false 
  // otherwise.
  // --------------------------------------------------------------------------
  virtual bool processAction(std::ifstream& inputFile, IStore* store);
};

#endif // !INVENTORY_

