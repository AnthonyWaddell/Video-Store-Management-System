// ---------------------------- history.h ------------------------------------
// Name and Section: Ryan Harlich, Rio Zhu, Anthony Waddell, Chris Salazar 
//                   CSS 343 B
// Created: February 17, 2018
// Date of Last Modification: February 23, 2018
// ---------------------------------------------------------------------------
// Purpose - Processes the history action.
// ---------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions: None.
// ---------------------------------------------------------------------------

#ifndef HISTORY_
#define HISTORY_

#include "iaction.h"

class History : public IAction
{
public:
  // ---------------------------- ~History ------------------------------------
  // An empty virtual destructor for extensibility.
  // Preconditions: None.
  // Postconditions: None.
  // --------------------------------------------------------------------------
  virtual ~History();

  // ---------------------------- processAction -------------------------------
  // Processes the history action reading what to do from a input file.
  // Preconditions: A valid IStore object. Correctly formatted input file line.
  // Postconditions: Input file ifstream will be at the end of the line.
  // Prints to the screen the customers history, if valid customer.
  // Parameter: inputFile - A input file with lines of properly formatted
  // commands.
  // store - An IStore object.
  // Return: Returns true if history displaying was successful, and false 
  // otherwise (invalid customer).
  // --------------------------------------------------------------------------
  virtual bool processAction(std::ifstream& inputFile, IStore* store);
};

#endif // !HISTORY_

