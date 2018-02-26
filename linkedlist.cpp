#include "linkedlist.h"

// --------------------------------------------------------------------------
// Basic constructor
// --------------------------------------------------------------------------
LinkedList::LinkedList()
{
	m_headPtr = NULL;
}

// --------------------------------------------------------------------------
// destructor, 99% sure temp won't cause a memory leak since didn't use "new"
// --------------------------------------------------------------------------
LinkedList::~LinkedList()
{
	// while there are more than one items in list
	while (m_headPtr->getNextPtr() != NULL)
	{
		// make temp to hold onto rest of list
		Node *temp = m_headPtr->getNextPtr();
		// delete head's pointer to item then delete head node
		delete m_headPtr->getItemPtr();
		delete m_headPtr;
		//set head to next item in list
		m_headPtr = temp;
	}
	//when there is only head left in list
	delete m_headPtr->getItemPtr();
	delete m_headPtr;
}

// --------------------------------------------------------------------------
// Remove front of linked list
// --------------------------------------------------------------------------
bool LinkedList::removeFront()
{
	bool removed = false;

	// If empty list
	if (m_headPtr == NULL)
	{
		return removed;
	}
	// If list with more than one item
	else if (m_headPtr->getNextPtr() != NULL)
	{
		Node *temp = m_headPtr->getNextPtr();
		delete m_headPtr->getItemPtr();
		delete m_headPtr;
		m_headPtr = temp;
		removed = true;
	}
	// If list with one item
	else
	{
		delete m_headPtr->getItemPtr();
		delete m_headPtr;
		m_headPtr = NULL;
		removed = true;
	}
	return removed;
}

// --------------------------------------------------------------------------
// Check for empty
// --------------------------------------------------------------------------
bool LinkedList::isEmpty()
{
	return (m_headPtr == NULL);
}
