#include "customer.h"

// --------------------------------------------------------------------------
// constructor with parameters
// --------------------------------------------------------------------------
Customer::Customer(string firstName, string lastName, int id)
{
	IPerson *new_customer = new IPerson(firstName, lastName, id);
	/*m_firstName = firstName;
	m_lastName = lastName;
	m_id = id;*/
}

// --------------------------------------------------------------------------
// destructor
// --------------------------------------------------------------------------
Customer::~Customer()
{
	while (!m_inventoryLLPtr->isEmpty())
	{
		m_inventoryLLPtr->removeFront();
	}
}

// --------------------------------------------------------------------------
// accessor for m_dvdHistory
// --------------------------------------------------------------------------
stack<string> Customer::getDVDHistory()
{
	return m_dvdHistory;
}

// --------------------------------------------------------------------------
// accessor for m_inventoryLLPtr
// --------------------------------------------------------------------------
LinkedList * Customer::getInventoryLLPtr()
{
	return m_inventoryLLPtr;
}
