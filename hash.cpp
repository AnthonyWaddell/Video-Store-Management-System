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
