// ---------------------------- afactory.h -----------------------------------
// Name and Section: Ryan Harlich, Rio Zhu, Anthony Waddell, Chris Salazar 
//                   CSS 343 B
// Created: February 17, 2018
// Date of Last Modification: February 23, 2018
// ---------------------------------------------------------------------------
// Purpose - A factory that returns an object of an IAction given the char
// symbol for the IAction.
// ---------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions: A factory
// design was used.
// ---------------------------------------------------------------------------

#ifndef AFACTORY_
#define AFACTORY_

#include "iaction.h"

class AFactory
{
public:
  // ---------------------------- ~AFactory -----------------------------------
  // An empty virtual destructor for extensibility.
  // Preconditions: None.
  // Postconditions: None.
  // --------------------------------------------------------------------------
  virtual ~AFactory();

  // ---------------------------- createAction --------------------------------
  // Returns a particular action object based on the argument passed in. Each
  // char symbol matches a particular IAction; in which, a desired object is
  // returned. Returns NULL if IAction does not exist.
  // Preconditions: None.
  // Postconditions: A IAction* is returned or NULL to indicate IAction does 
  // not exist. IAction* needs to be deallocated appropriately by client.
  // Parameter: actionType - A char symbol to match a particular IAction to be
  // returned.
  // Return: Returns a desired IAction object.
  // --------------------------------------------------------------------------
  static IAction* createAction(char actionType);
};

#endif // !AFACTORY_

