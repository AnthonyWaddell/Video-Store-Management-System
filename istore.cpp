#include "istore.h"

// --------------------------------------------------------------------------
// accessor for m_inventoryLLPtr
// --------------------------------------------------------------------------
LinkedList * IStore::getInventoryLLPtr()
{
	return m_inventoryLLPtr;
}

// --------------------------------------------------------------------------
// accessor for m_customerHashPtr
// --------------------------------------------------------------------------
Hash * IStore::getCustomerHashTablePtr()
{
	return m_customerHashPtr;
}
