#include "iperson.h"

// --------------------------------------------------------------------------
// constructor, needs to incorporate hashKey
// --------------------------------------------------------------------------
IPerson::IPerson(std::string firstName, std::string lastName, int hashKey)
{
	m_firstName = firstName;
	m_lastName = lastName;

}

// --------------------------------------------------------------------------
// destructor
// --------------------------------------------------------------------------
IPerson::~IPerson()
{
}

// --------------------------------------------------------------------------
// accessor for m_hashKey
// --------------------------------------------------------------------------
int IPerson::getHashKey()
{
	return m_hashKey;
}

// --------------------------------------------------------------------------
// accessor for m_firstName
// --------------------------------------------------------------------------
std::string IPerson::getFirstName()
{
	return m_firstName;
}

// accessor for m_lastName
// destructor
// --------------------------------------------------------------------------
std::string IPerson::getLastName()
{
	return m_lastName;
}
