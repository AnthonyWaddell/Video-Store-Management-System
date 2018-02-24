// ---------------------------- iaction.h ------------------------------------
// Name and Section: Ryan Harlich, Rio Zhu, Anthony Waddell, Chris Salazar 
//                   CSS 343 B
// Created: February 17, 2018
// Date of Last Modification: February 23, 2018
// ---------------------------------------------------------------------------
// Purpose - Interface for an action.
// ---------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions: None.
// ---------------------------------------------------------------------------

#ifndef IACTION_
#define IACTION_

#include "istore.h"

#include <fstream>

class IAction
{
public:
  // ---------------------------- ~History ------------------------------------
  // An empty virtual destructor for extensibility.
  // Preconditions: None.
  // Postconditions: None.
  // --------------------------------------------------------------------------
  virtual ~IAction();

  // ---------------------------- processAction -------------------------------
  // Pure virtual method for a processing an action.
  // Preconditions: A valid IStore object. Correctly formatted input file line.
  // Postconditions: Input file ifstream will be at the end of the line.
  // Parameter: inputFile - A input file with lines of properly formatted
  // commands.
  // store - An IStore object.
  // Return: Returns true if IAction was successful, and false 
  // otherwise.
  // --------------------------------------------------------------------------
  virtual bool processAction(std::ifstream& inputFile, IStore* store) = 0;
};

#endif // !IACTION_

