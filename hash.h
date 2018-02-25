// ---------------------------- hash.h ---------------------------------------
// Name and Section: Ryan Harlich, Rio Zhu, Anthony Waddell, Chris Salazar 
//                   CSS 343 B
// Created: February 17, 2018
// Date of Last Modification: February 23, 2018
// ---------------------------------------------------------------------------
// Purpose - Stores people pointers by their key/hash key into a hash table. 
// Also, receives people pointer from the Hash Table with their hash key.
// ---------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions: Linear closed
// hashing was used.
// ---------------------------------------------------------------------------

#ifndef HASH_
#define HASH_

#include "iperson.h"
#include "customer.h"

const int TABLE_SIZE = 2003; // Size of hash table

class Hash
{
public:
  // ---------------------------- Hash ----------------------------------------
  // Default constructor which initializes a hash table object of size 
  // TABLE_SIZE and initializes all slots to NULL.
  // Preconditions: None.
  // Postconditions: None.
  // --------------------------------------------------------------------------
  Hash();

  // ---------------------------- ~Hash ---------------------------------------
  // Destructor which deletes all objects in elements that do not contain NULL
  // and sets elements to NULL after deallocating. After that, the hash table
  // is deallocated.
  // Preconditions: None.
  // Postconditions: None.
  // --------------------------------------------------------------------------
  virtual ~Hash();

  // ---------------------------- insert --------------------------------------
  // Inserts a IPerson* into the hash table with linear closed hashing. Based 
  // off IPerson's hash key. In the case of customers, their hash key is their 
  // id.
  // Preconditions: IPerson has a valid unique hash key. Hash table is not 
  // full.
  // Postconditions: Hash table contains newly inserted IPerson* if table is 
  // not full.
  // Parameter: person - A IPerson* that is to be inserted into the hash table.
  // --------------------------------------------------------------------------
  bool insert(IPerson* person);

  // ---------------------------- ~Hash ---------------------------------------
  // Retrieves and returns a IPerson* given their hash key. In the case of a
  // customer it is their id. Returns NULL if person is not found.
  // Preconditions: None.
  // Postconditions: Returns IPerson*, or NULL in which case client has to 
  // print friendly message stating customer does not exist.
  // Parameter: key - the hash key that uniquely identifies a IPerson
  // Return: Returns a IPerson* from the hash table or NULL to indicate IPerson
  // not found.
  // --------------------------------------------------------------------------
  IPerson* retrieve(int key);

private:
  IPerson** m_hashTable; // A hash table of IPerson pointers
};

#endif // !HASH_

