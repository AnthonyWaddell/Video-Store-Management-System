#include "drama.h"

// --------------------------------------------------------------------------
//	Destructor
// --------------------------------------------------------------------------
Drama::~Drama()
{
}

// --------------------------------------------------------------------------
//	display object information to designated output stream
// --------------------------------------------------------------------------
void Drama::display(ostream & outStream) const
{
	outStream << m_genreAbbrev << ", " << m_stock << ", " << m_director <<
		", " << m_title << ", " << m_yearReleased;
}

// --------------------------------------------------------------------------
//	create string with relevant properties of this dvd
// --------------------------------------------------------------------------
void Drama::genDisplay(string & genDisplayString)
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
void Drama::genCopy(IItem * itemPtr)
{
	Drama *temp = static_cast<Drama*>(itemPtr);
	if (temp->getGenre() == 'D')
	{

		this->m_stock = temp->m_stock;
		this->m_director = temp->m_director;
		this->m_title = temp->m_title;
		this->m_yearReleased = temp->m_yearReleased;
	}
}

// --------------------------------------------------------------------------
//	compare this drama dvd to any other dvd, regardless of genre 
// --------------------------------------------------------------------------
int Drama::compare(IItem * itemPtr)
{
	// DVD dorting order is Comedy, then drama, then classic, we can assume
	// that no genre goes after classic, unless it is classic as well (then 
	// its sorted by compareDVD

	int return_value = 0;
	// Cast the comparator to dvd type
	DVD *temp = static_cast<DVD*>(itemPtr);
	char other_genre = temp->getGenre();

	// Comedy goes before drama
	if (other_genre == 'F')
	{
		return_value = -1;
	}
	// If both are drama, must sort further 
	if (other_genre == 'D')
	{
		return_value = compareDVD(temp);
	}
	// Classical goes after drama
	if (other_genre == 'C')
	{
		return_value = 1;
	}
	return return_value;
}

// --------------------------------------------------------------------------
//	Fill relevant properties of a Drama DVD with information from input file
// --------------------------------------------------------------------------
void Drama::buildDVD(char genre, ifstream & inputFileInventory)
{
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
bool Drama::operator==(IItem * itemPtr)
{
	bool equal = false;
	Drama *temp = static_cast<Drama*>(itemPtr);
	if (m_title == temp->getTitle() && m_director == temp->getDirector())
	{
		equal = true;
	}
	return equal;
}

// --------------------------------------------------------------------------
//	Compare drama dvd's
// --------------------------------------------------------------------------
int Drama::compareDVD(DVD * dvdPtr)
{
	int return_value = 0;
	Drama *temp = static_cast<Drama*>(dvdPtr);
	// Treat dvdPtr as a drama to compare by director first
	return_value = this->compareDirector(temp->getDirector());

	// If they have the same director, then must further compare by title
	if (return_value == 0)
	{
		return_value = this->compareTitle(temp->getTitle());
	}

	return return_value;
}

// --------------------------------------------------------------------------
//	Compare by director, 
// --------------------------------------------------------------------------
int Drama::compareDirector(string director)
{
	int return_value = 0;

	// if other title goes after
	if (m_director < director)
	{
		return_value = 1;
	}
	//If other director goes before
	if(m_director > director)
	{
		return_value = -1;
	}
	return return_value;
}

// --------------------------------------------------------------------------
//	compare objects by title
// --------------------------------------------------------------------------
int Drama::compareTitle(string title)
{
	int return_value = 0;

	// if other title goes after
	if (m_title < title)
	{
		return_value = 1;

	}
	// If other title goes before
	if (m_title > title)
	{
		return_value = -1;
	}
	return return_value;
}