#include "dvd.h"

// --------------------------------------------------------------------------
// constructor
// --------------------------------------------------------------------------
DVD::DVD()
{
}

// --------------------------------------------------------------------------
// destructor
// --------------------------------------------------------------------------
DVD::~DVD()
{
}

// --------------------------------------------------------------------------
// accessor for m_genreAbbrev;
// --------------------------------------------------------------------------
char DVD::getGenre()
{
	return m_genreAbbrev;
}

// --------------------------------------------------------------------------
// accessor for m_director;
// --------------------------------------------------------------------------
string DVD::getDirector()
{
	return m_director;
}

// --------------------------------------------------------------------------
// mutator for m_director
// --------------------------------------------------------------------------
void DVD::setDirector(string director)
{
	m_director = director;
}

// --------------------------------------------------------------------------
// mutator for m_genreAbbrev
// --------------------------------------------------------------------------
void DVD::setGenreAbbrev(char genreAbbrev)
{
	//Not sure if we should error check this to only allow  F D and/or C
	m_genreAbbrev = genreAbbrev;
}

// --------------------------------------------------------------------------
// compares by genre for sorting/inserting purposes
// --------------------------------------------------------------------------
int DVD::compareByGenre(char genre)
{
	int return_value;

	switch (toupper(this->m_genreAbbrev))
	{
	case 'F':
		if (genre == 'F')
			return_value = 0;
		if (genre == 'D')
			return_value = 1;
		if (genre == 'C')
			return_value = 1;
		break;
	case 'D':
		if (genre == 'F')
			return_value = -1;
		if (genre == 'D')
			return_value = 0;
		if (genre == 'C')
			return_value = 1;
		break;
	case 'C':
		if (genre == 'F')
			return_value = -1;
		if (genre == 'D')
			return_value = -1;
		if (genre == 'C')
			return_value = 0;
		break;
	default:
		cout << "Invalid genre" << endl;
	}
	return return_value;
}

