// ---------------------------- iperson.h ------------------------------------
// Name and Section: Ryan Harlich, Rio Zhu, Anthony Waddell, Chris Salazar 
//                   CSS 343 B
// Created: February 17, 2018
// Date of Last Modification: February 23, 2018
// ---------------------------------------------------------------------------
// Purpose - Interface for a person.
// ---------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions: None.
// ---------------------------------------------------------------------------

#ifndef IPERSON_
#define IPERSON_

#include <string> // For string

class IPerson
{
public:
  // ---------------------------- IPerson -------------------------------------
  // A constructor for an IPerson, storing name and hash key.
  // Preconditions: A valid unique hash key.
  // Postconditions: IPerson has a name and hash key.
  // Parameter: firstName - first name of IPerson.
  // lastName - last name of IPerson.
  // hashKey - unique hash key identifier of IPerson.
  // --------------------------------------------------------------------------
  IPerson(std::string firstName, std::string lastName, int hashKey);

  // ---------------------------- ~IPerson ------------------------------------
  // An empty virtual destructor for extensibility.
  // Preconditions: None.
  // Postconditions: None.
  // --------------------------------------------------------------------------
  virtual ~IPerson();

  // ---------------------------- getHashKey ----------------------------------
  // Gets IPerson's hash key.
  // Preconditions: None.
  // Postconditions: None.
  // Return: Returns hash key of IPerson.
  // --------------------------------------------------------------------------
  int getHashKey();

  // ---------------------------- getFirstName --------------------------------
  // Gets IPerson's first name.
  // Preconditions: None.
  // Postconditions: None.
  // Return: Returns first name of IPerson.
  // --------------------------------------------------------------------------
  std::string getFirstName();

  // ---------------------------- getLastName ---------------------------------
  // Gets IPerson's last name.
  // Preconditions: None.
  // Postconditions: None.
  // Return: Returns last name of IPerson.
  // --------------------------------------------------------------------------
  std::string getLastName();

private:
  std::string m_firstName; // First name of IPerson
  std::string m_lastName;  // Last name of IPerson
  int m_hashKey;           // Hash key of IPerson
};

#endif // !IPERSON_

