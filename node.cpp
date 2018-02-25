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
