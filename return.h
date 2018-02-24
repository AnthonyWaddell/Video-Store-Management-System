// ---------------------------- return.h -------------------------------------
// Name and Section: Ryan Harlich, Rio Zhu, Anthony Waddell, Chris Salazar 
//                   CSS 343 B
// Created: February 17, 2018
// Date of Last Modification: February 23, 2018
// ---------------------------------------------------------------------------
// Purpose - Processes the return action.
// ---------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions: None.
// ---------------------------------------------------------------------------

#ifndef RETURN_
#define RETURN_

#include "iaction.h"

class Return : public IAction
{
public:
  // ---------------------------- ~Return -------------------------------------
  // An empty virtual destructor for extensibility.
  // Preconditions: None.
  // Postconditions: None.
  // --------------------------------------------------------------------------
  virtual ~Return();

  // ---------------------------- processAction -------------------------------
  // Processes the return action reading what to do from a input file.
  // Preconditions: A valid IStore object. Correctly formatted input file line.
  // Postconditions: Input file ifstream will be at the end of the line. IStore
  // will have added movie to its inventory and removed from the customer's
  // inventory if a valid movie and valid customer; otherwise, error message
  // is printed to screen. Also, the return, if valid, will be added to
  // customer's history.
  // Parameter: inputFile - A input file with lines of properly formatted
  // commands.
  // store - An IStore object.
  // Return: Returns true if return was successful, and false otherwise.
  // --------------------------------------------------------------------------
  virtual bool processAction(std::ifstream& inputFile, IStore* store);
};

#endif // !RETURN_

