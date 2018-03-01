#include "comedy.h"

// --------------------------------------------------------------------------
//	Destructor
// --------------------------------------------------------------------------
Comedy::~Comedy()
{
}

// --------------------------------------------------------------------------
//	Display function to output stream
// --------------------------------------------------------------------------
void Comedy::display(ostream & outStream) const
{
	outStream << m_genreAbbrev << ", " << m_stock << ", " << m_director <<
		", " << m_title << ", " << m_yearReleased;
}

// --------------------------------------------------------------------------
//	Display function, really not sure if this is what this is supposed to do?
// --------------------------------------------------------------------------
void Comedy::genDisplay(string & genDisplayString)
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
	genDisplayString += m_yearReleased;
}

// --------------------------------------------------------------------------
//	copy properties of itemPtr to *this
// --------------------------------------------------------------------------
void Comedy::genCopy(IItem * itemPtr)
{
	Comedy *temp = static_cast<Comedy*>(itemPtr);
	if (temp->getGenre() == 'F')
	{

		this->m_stock = temp->m_stock;
		this->m_director = temp->m_director;
		this->m_title = temp->m_title;
		this->m_yearReleased = temp->m_yearReleased;
	}
}

// --------------------------------------------------------------------------
//	compare this comedy dvd to any other dvd, regardless of genre 
// --------------------------------------------------------------------------
int Comedy::compare(IItem * itemPtr)
{
	// DVD dorting order is Comedy, then drama, then classic, we can assume
	// that no genre goes before comedy, unless it is comedy as well (then 
	// its sorted by compareDVD
	int return_value = 1;
	// Cast the comparator to dvd type
	DVD *temp = static_cast<DVD*>(itemPtr);
	char other_genre = temp->getGenre();

	// If comparing against comedy, must sort further
	if (other_genre == 'F')
	{
		return_value = compareDVD(temp);
	}
	
	// Otherwise, drama and classic both go after comedy
	return return_value;
}

// --------------------------------------------------------------------------
//	Build a comedy dvd
// --------------------------------------------------------------------------
void Comedy::buildDVD(char genre, std::ifstream & inputFileInventory)
{
	//F, 10, Nora Ephron, You've Got Mail, 1998
	// This needs error handling

	this->setGenreAbbrev(genre);
	inputFileInventory >> this->m_stock;
	//maybe a cin.get() or cin.ignore() to eat up space/comma
	getline(inputFileInventory, this->m_director, ',');
	getline(inputFileInventory, this->m_title, ',');
	//maybe a cin.get() or cin.ignore() to eat up the space/comma
	inputFileInventory >> this->m_yearReleased;
}

// --------------------------------------------------------------------------
//	Overloaded boolean equality operator, not sure if we are checking anything other than title and director
// --------------------------------------------------------------------------
bool Comedy::operator==(IItem * itemPtr)
{
	bool equal = false;
	Comedy *temp = static_cast<Comedy*>(itemPtr);
	if (m_title == temp->getTitle() && m_director == temp->getDirector())
	{
		equal = true;
	}
	return equal;
}

// --------------------------------------------------------------------------
//	compare comedy objects by year released
// --------------------------------------------------------------------------
int Comedy::compareDVD(DVD * dvdPtr)
{
	int return_value = 0;
	Comedy *temp = static_cast<Comedy*>(dvdPtr);
	// Treat dvdPtr as a comedy to compare by title first
	return_value = this->compareTitle(temp->getTitle());

	// If they have the same title, then must further compare by year released
	if (return_value == 0)
	{
		return_value = this->compareYearReleased(temp->getYearReleased());
	}

	return return_value;
}

// --------------------------------------------------------------------------
//	compare objects by title
// --------------------------------------------------------------------------
int Comedy::compareTitle(string title)
{
	int return_value = 0;

	// if other title goes after
	if (m_title < title)
	{
		return_value = 1;

	}
	// If other title goes before
	if(m_title > title)
	{
		return_value = -1;
	}
	return return_value;
}

// --------------------------------------------------------------------------
//	compare objects by year released
// --------------------------------------------------------------------------
int Comedy::compareYearReleased(int year)
{
	int return_value = 0;

	// if other year goes after
	if (m_yearReleased < year)
	{
		return_value = 1;

	}
	// If they have same release year
	else if (m_yearReleased == year)
	{
		return return_value;
	}
	// If other year goes before
	else
	{
		// m_yearReleased > year
		return_value = -1;
	}
	return return_value;
}
