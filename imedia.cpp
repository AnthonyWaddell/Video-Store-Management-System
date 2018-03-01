#include "imedia.h"

// --------------------------------------------------------------------------
// destructor
// --------------------------------------------------------------------------
IMedia::~IMedia()
{
}

// --------------------------------------------------------------------------
// accessor for m_yearReleased
// --------------------------------------------------------------------------
int IMedia::getYearReleased()
{
	return m_yearReleased;
}

// --------------------------------------------------------------------------
// accessor for m_title
// --------------------------------------------------------------------------
string IMedia::getTitle()
{
	return m_title;
}

// --------------------------------------------------------------------------
// accessor for m_mediaTypeAbbrev
// --------------------------------------------------------------------------
char IMedia::getMediaTypeAbbrev()
{
	return m_mediaTypeAbbrev;
}

// --------------------------------------------------------------------------
// mutator for m_title
// --------------------------------------------------------------------------
void IMedia::setTitle(string title)
{
	m_title = title;
}

// --------------------------------------------------------------------------
// mutator for m_yearReleased;
// --------------------------------------------------------------------------
void IMedia::setYearReleased(int yearReleased)
{
	int current_year = 2018;
	// Not sure if we wanna set upper or lower limits for year release
	if (yearReleased <= current_year)
	{
		m_yearReleased = yearReleased;
	}
}

// --------------------------------------------------------------------------
// mutator for mediaTypeAbbrev;
// --------------------------------------------------------------------------
void IMedia::setMediaTypeAbbrev(char mediaTypeAbbrev)
{
	// Not sure if we are error checking this or not for anything besides 'D'
	m_mediaTypeAbbrev = mediaTypeAbbrev;
}

