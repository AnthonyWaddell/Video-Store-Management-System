// ---------------------------- dfactory.h -----------------------------------
// Name and Section: Ryan Harlich, Rio Zhu, Anthony Waddell, Chris Salazar 
//                   CSS 343 B
// Created: February 17, 2018
// Date of Last Modification: February 23, 2018
// ---------------------------------------------------------------------------
// Purpose - A factory that returns an object of an DVD given the char
// symbol for the DVD.
// ---------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions: A factory
// design was used.
// ---------------------------------------------------------------------------

#ifndef DFACTORY_
#define DFACTORY_

#include "dvd.h"

class DFactory
{
public:
  // ---------------------------- ~DFactory -----------------------------------
  // An empty virtual destructor for extensibility.
  // Preconditions: None.
  // Postconditions: None.
  // --------------------------------------------------------------------------
  virtual ~DFactory();

  // ---------------------------- createDVD -----------------------------------
  // Returns a particular DVD object based on the argument passed in. Each
  // char symbol matches a particular DVD; in which, a desired object is
  // returned. Returns NULL if DVD does not exist.
  // Preconditions: None.
  // Postconditions: A DVD* is returned or NULL to indicate DVD does 
  // not exist. DVD* needs to be deallocated appropriately by client.
  // Parameter: genre - A char symbol to match a particular DVD to be
  // returned.
  // Return: Returns a desired DVD object.
  // --------------------------------------------------------------------------
  static DVD* createDVD(char genre);
};

#endif // !DFACTORY_

