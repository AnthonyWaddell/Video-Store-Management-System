#include "node.h"

// --------------------------------------------------------------------------
// node constructor
// --------------------------------------------------------------------------
Node::Node()
{
	m_itemPtr = NULL;
	m_nextNodePtr = NULL;
}

// --------------------------------------------------------------------------
// node constructor w/ content param
// --------------------------------------------------------------------------
Node::Node(IItem * itemPtr)
{
	m_itemPtr = itemPtr;
	m_nextNodePtr = NULL;
}

// --------------------------------------------------------------------------
// node constructor w/ content param 
// --------------------------------------------------------------------------
Node::Node(IItem * itemPtr, Node * nextNodePtr)
{
	m_itemPtr = itemPtr;
	m_nextNodePtr = nextNodePtr;
}

// --------------------------------------------------------------------------
// node destructor 
// --------------------------------------------------------------------------
Node::~Node()
{
	if (m_itemPtr != NULL)
	{
		m_itemPtr = NULL;
	}
}

// --------------------------------------------------------------------------
// accessor for m_itemPtr
// --------------------------------------------------------------------------
IItem * Node::getItemPtr()
{
	IItem * temp = this->m_itemPtr;
	return temp;
}

// --------------------------------------------------------------------------
// accessor for m_nextNodePtr 
// --------------------------------------------------------------------------
Node * Node::getNextPtr()
{
	Node *temp = this->m_nextNodePtr;
	return temp;
}

// --------------------------------------------------------------------------
// mutator for next node pointer 
// --------------------------------------------------------------------------
void Node::setNextPtr(Node * nextPtr)
{
	this->m_nextNodePtr = nextPtr;
}

// --------------------------------------------------------------------------
// mutator for next node pointer 
// --------------------------------------------------------------------------
void Node::setItemPtr(IItem * itemPtr)
{
	this->m_itemPtr = itemPtr;
}
