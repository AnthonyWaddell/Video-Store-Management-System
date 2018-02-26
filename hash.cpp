#include "hash.h"

// --------------------------------------------------------------------------
// hash table constructor
// --------------------------------------------------------------------------
Hash::Hash()
{
	m_hashTable = new IPerson*[TABLE_SIZE];

	for (int i = 0; i < TABLE_SIZE; i++)
	{
		m_hashTable[i] = NULL;
	}
}

// --------------------------------------------------------------------------
// destructor
// --------------------------------------------------------------------------
Hash::~Hash()
{
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		if (m_hashTable[i] != NULL)
		{
			// Think this is gonna cause a memory leak
			delete m_hashTable[i];
			m_hashTable[i] = NULL;
		}
	}
	delete m_hashTable;
}

// --------------------------------------------------------------------------
// insert
// --------------------------------------------------------------------------
bool Hash::insert(IPerson* person)
{
	if (person->getHashKey() < TABLE_SIZE || person->getHashKey() > 0)
	{
		int hashVal;
		hashVal = person->getHashKey() % TABLE_SIZE;
		m_hashTable[hashVal] = person;
		return true;
	}
	else
	{
		return false;
	}
}

// --------------------------------------------------------------------------
// retrieve
// --------------------------------------------------------------------------
IPerson* Hash::retrieve(int key)
{
	if (m_hashTable[key] == NULL)
	{
		return NULL;
	}
	else
	{
		return m_hashTable[key];
	}
}