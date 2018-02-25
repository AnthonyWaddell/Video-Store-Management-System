#include "dfactory.h"
#include <iostream>
using namespace std;

// --------------------------------------------------------------------------
// destructor
// --------------------------------------------------------------------------
DFactory::~DFactory()
{
}

// --------------------------------------------------------------------------
// return pointer to dvd type
// --------------------------------------------------------------------------
DVD * DFactory::createDVD(char genre)
{
	DVD *m_dvd = NULL;
	genre = toupper(genre);

	switch (genre)
	{
	case 'F':
		m_dvd = new Comedy();
		break;
	case 'D':
		m_dvd = new Drama();
		break;
	case 'C':
		m_dvd = new Classical();
		break;
	default:
		cout << "Incompatible genre" << endl;
		break;
	}
	return m_dvd;
}
