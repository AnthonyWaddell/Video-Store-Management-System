#include "afactory.h"
#include <iostream>
using namespace std;

// --------------------------------------------------------------------------
// destructor
// --------------------------------------------------------------------------
AFactory::~AFactory()
{
}

// --------------------------------------------------------------------------
// action factory
// --------------------------------------------------------------------------
IAction * AFactory::createAction(char actionType)
{
	IAction *m_action = NULL;
	actionType = toupper(actionType);
	switch (actionType)
	{
	case 'B':
		m_action = new Borrow();
		break;
	case 'R':
		m_action = new Return();
		break;
	case 'H':
		m_action = new History();
		break;
	case 'I':
		m_action = new Inventory();
		break;
	default:
		cout << "Invalid action" << endl;
		break;
	}
	return m_action;
}
