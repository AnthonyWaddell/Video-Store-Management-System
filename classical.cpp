#include "classical.h"

// --------------------------------------------------------------------------
//	Destructor
// --------------------------------------------------------------------------
Classical::~Classical()
{
}

// --------------------------------------------------------------------------
//	Display function to output stream
// --------------------------------------------------------------------------
void Classical::display(ostream & outStream) const
{
	outStream << m_genreAbbrev << ", " << m_stock << ", " << m_director <<
		", " << m_title << ", " << m_majorActorFirstName << " " <<
		m_majorActorLastName << " " << m_monthReleased << " " <<
		m_yearReleased;
}

// --------------------------------------------------------------------------
//	Display function, really not sure if this is what this is supposed to do?
// --------------------------------------------------------------------------
void Classical::genDisplay(string & genDisplayString)
{
	string comma_space = ", ";
	string space = " ";
	genDisplayString += m_genreAbbrev;
	genDisplayString += comma_space;
	genDisplayString += m_stock;
	genDisplayString += comma_space;
	genDisplayString += m_director;
	genDisplayString += comma_space;
	genDisplayString += m_title;
	genDisplayString += comma_space;
	genDisplayString += m_majorActorFirstName;
	genDisplayString += space;
	genDisplayString += m_majorActorLastName;
	genDisplayString += space;
	genDisplayString += m_monthReleased;
	genDisplayString += space;
	genDisplayString += m_yearReleased;
}

// --------------------------------------------------------------------------
//	copy properties of itemPtr to *this
// --------------------------------------------------------------------------
void Classical::genCopy(IItem * itemPtr)
{
	Classical *temp = static_cast<Classical*>(itemPtr);
	if (temp->getGenre() == 'C')
	{
		this->m_stock = temp->m_stock;
		this->m_director = temp->m_director;
		this->m_title = temp->m_title;
		this->m_majorActorFirstName = temp->m_majorActorFirstName;
		this->m_majorActorLastName = temp->m_majorActorLastName;
		this->m_monthReleased = temp->m_monthReleased;
		this->m_yearReleased = temp->m_yearReleased;
	}
}

// --------------------------------------------------------------------------
//	compare this classical dvd to any other dvd, regardless of genre 
// --------------------------------------------------------------------------
int Classical::compare(IItem * itemPtr)
{
	// DVD dorting order is Comedy, then drama, then classic, we can assume
	// that no genre goes after classic, unless it is classic as well (then 
	// its sorted by compareDVD
	int return_value = -1;
	// Cast the comparator to dvd type
	DVD *temp = static_cast<DVD*>(itemPtr);
	char other_genre = temp->getGenre();

	// If comparing against classic, must sort further
	if (other_genre == 'C')
	{
		return_value = compareDVD(temp);
	}

	// Otherwise, comedy and drama both go before classical
	return return_value;
}

// --------------------------------------------------------------------------
//	Build a classical dvd
// --------------------------------------------------------------------------
void Classical::buildDVD(char genre, ifstream & inputFileInventory)
{
	// This needs error handling


	//C, 10, Victor Fleming, The Wizard of Oz, Judy Garland 7 1939
	this->setGenreAbbrev(genre);
	inputFileInventory >> this->m_stock;
	//maybe a cin.get() or cin.ignore() to eat up space/comma
	getline(inputFileInventory, this->m_director, ',');
	getline(inputFileInventory, this->m_title, ',');
	inputFileInventory >> this->m_majorActorFirstName;
	//maybe a cin.get() or cin.ignore() to eat up the space
	inputFileInventory >> this->m_majorActorLastName;
	//maybe a cin.get() or cin.ignore() to eat up the space
	inputFileInventory >> this->m_monthReleased;
	inputFileInventory >> this->m_yearReleased;
}

// --------------------------------------------------------------------------
//	Overloaded boolean equality operator, not sure if we are checking anything other than title and director
// --------------------------------------------------------------------------
bool Classical::operator==(IItem * itemPtr)
{
	bool equal = false;
	Classical *temp = static_cast<Classical*>(itemPtr);
	if (m_title == temp->getTitle() && m_director == temp->getDirector())
	{
		equal = true;
	}
	return equal;
}

// --------------------------------------------------------------------------
//	accessor for m_monthReleased
// --------------------------------------------------------------------------
int Classical::getMonthReleased()
{
	return m_monthReleased;
}

// --------------------------------------------------------------------------
//	accessor for m_majorActorFirstName
// --------------------------------------------------------------------------
string Classical::getMajorActorFirstName()
{
	return m_majorActorFirstName;
}

// --------------------------------------------------------------------------
//	accessor for m_majorActorLastName
// --------------------------------------------------------------------------
string Classical::getMajorActorLastName()
{
	return m_majorActorLastName;
}

// --------------------------------------------------------------------------
// mutator for m_monthReleased
// --------------------------------------------------------------------------
void Classical::setMonthReleased(int month)
{
	int january = 1;
	int december = 12;

	if (month >= january && month <= december)
	{
		m_monthReleased = month;
	}
}

// --------------------------------------------------------------------------
//	mutator for m_majorActorFirstName
// --------------------------------------------------------------------------
void Classical::setMajorActorFirstName(string firstName)
{
	m_majorActorFirstName = firstName;
}

// --------------------------------------------------------------------------
//	mutator for m_majorActorLastName
// --------------------------------------------------------------------------
void Classical::setMajorActorLastName(string lastName)
{
	m_majorActorLastName = lastName;
}

// --------------------------------------------------------------------------
//	Compare two classical dvds
// --------------------------------------------------------------------------
int Classical::compareDVD(DVD * dvdPtr)
{
	int return_value = 0;
	Classical *temp = static_cast<Classical*>(dvdPtr);
	// Treat dvdPtr as a classical to compare by m_monthReleased
	return_value = this->compareReleaseDate
	(temp->getMonthReleased(), temp->getYearReleased());

	// If they have the same release date must compare by actor;
	if (return_value == 0)
	{
		return_value = this->compareMajorActor
		(temp->getMajorActorFirstName(), temp->getMajorActorLastName());
	}

	return return_value;
}

// --------------------------------------------------------------------------
//	compare by release date, in progress
// --------------------------------------------------------------------------
int Classical::compareReleaseDate(int month, int year)
{
	int return_value = 0;

	// If *this came out before comparator
	if (m_yearReleased < year)
	{
		return_value = 1;
	}
	// If both items came out in the same year
	else if (m_yearReleased == year)
	{
		//If *this came out before comparator
		if (m_monthReleased < month)
		{
			return_value = 1;
		}
		// If they are the same
		else if (m_monthReleased == month)
		{
			return return_value;
		}
		// If this came out after comparator
		else
		{
			// (m_monthReleased > month)
			return_value = -1;
		}
	}
	// If *this came out after comparator
	else
	{
		// (m_yearReleased > year)
		return_value = -1;
	}
	return return_value;
}

// --------------------------------------------------------------------------
//	Compare by major actor
// --------------------------------------------------------------------------
int Classical::compareMajorActor(string firstName, string lastName)
{

	int return_value = 0;

	// If this goes before other actor
	if (m_majorActorLastName < lastName)
	{
		return_value = 1;

	}
	// If actors have same last name
	else if (m_majorActorLastName == lastName)
	{
		// If this goes before other actor
		if (m_majorActorFirstName < firstName)
		{
			return_value = 1;
		}
		// If it is same actor
		else if (m_majorActorFirstName == firstName)
		{
			return return_value;
		}
		// If this goes after other actor
		else
		{
			// m_majorActorFirstName > firstName
			return_value = -1;
		}
	}
	// If other actor goes before this
	else
	{
		//m_majorActorLastName > lastName
		return_value = -1;
	}
	return return_value;
}