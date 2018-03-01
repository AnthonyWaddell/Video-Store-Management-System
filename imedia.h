// ---------------------------- imedia.h -------------------------------------
// Name and Section: Ryan Harlich, Rio Zhu, Anthony Waddell, Chris Salazar 
//                   CSS 343 B
// Created: February 17, 2018
// Date of Last Modification: February 23, 2018
// ---------------------------------------------------------------------------
// Purpose - An media interface. Includes things such as DVD, music, and etc.
// ---------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions: None.
// ---------------------------------------------------------------------------

#ifndef IMEDIA_
#define IMEDIA_

#include "iitem.h"
#include <string>
using namespace std;

class IMedia : public IItem
{
public:
  // ---------------------------- ~IMedia -------------------------------------
  // An empty virtual destructor for extensibility.
  // Preconditions: None.
  // Postconditions: None.
  // --------------------------------------------------------------------------
  virtual ~IMedia();

  // ---------------------------- display -------------------------------------
  // Displays media information.
  // Preconditions: None.
  // Postconditions: outStream contains media information.
  // Parameter: outStream - A out stream for the display.
  // --------------------------------------------------------------------------
  virtual void display(std::ostream& outStream) const = 0;

  // ---------------------------- genDisplay ----------------------------------
  // Generates the display information into a string.
  // Preconditions: None.
  // Postconditions: genDisplayString contains media information.
  // Parameter: genDisplayString - A string that will contain the media's
  // information after the method executes.
  // --------------------------------------------------------------------------
  virtual void genDisplay(std::string& genDisplayString) = 0;

  // ---------------------------- displaySearchKey ----------------------------
  // Displays the search key information of the media.
  // Preconditions: None.
  // Postconditions: outStream contains media search key information.
  // Parameter: outStream - A out stream for the display.
  // --------------------------------------------------------------------------
  virtual void displaySearchKey(std::ostream& outStream) = 0;

  // ---------------------------- genSearchKey --------------------------------
  // Generates an media that only contains its search key information.
  // Preconditions: None.
  // Postconditions: This media has its search key information updated. 
  // ifStream will be at the end of its line.
  // Parameter: inputFile - A file the contains the search key of the media.
  // --------------------------------------------------------------------------
  virtual void genSearchKey(std::ifstream& inputFile) = 0;

  // ---------------------------- compareSearchKey ----------------------------
  // Detects if media is the same purely based of its search key information.
  // Preconditions: itemPtr is a type of media.
  // Postconditions: None.
  // Parameter: itemPtr - Item to compare against to see if it is the same
  // item based of a search key information.
  // Return: Returns true if item is same as item with search key information
  // --------------------------------------------------------------------------
  virtual bool compareSearchKey(IItem* itemPtr) = 0;

  // ---------------------------- genCopy -------------------------------------
  // Generates a copy of an item so all of this media fields are the same as
  // the parameters items fields.
  // Preconditions: itemPtr is a type of media.
  // Postconditions: This media contains the same fields as the parameter item.
  // Parameter: itemPtr - Item to copy its member variables.
  // --------------------------------------------------------------------------
  virtual void genCopy(IItem* itemPtr) = 0;

  // ---------------------------- compare -------------------------------------
  // Compares two medias determining if should go ahead of media, is same 
  // media, or goes after media.
  // Preconditions: itemPtr is a type of media.
  // Postconditions: None.
  // Parameter: itemPtr - An item to compare against.
  // Return: Returns -1 for goes before, 0 forst same, and 1 for goes after.
  // --------------------------------------------------------------------------
  virtual int compare(IItem* itemPtr) = 0;

  // ---------------------------- operator== ----------------------------------
  // Compares if two medias are the same.
  // Preconditions: itemPtr is a type of media.
  // Postconditions: None.
  // Parameter: itemPtr - An item to compare against.
  // Return: Returns true if media is the same, false otherwise.
  // --------------------------------------------------------------------------
  virtual bool operator==(IItem* itemPtr) = 0;

  // ---------------------------- getYearReleased -----------------------------
  // Gets the year media was released.
  // Preconditions: None.
  // Postconditions: None.
  // Return: Returns year media was released.
  // --------------------------------------------------------------------------
  int getYearReleased();

  // ---------------------------- getTitle ------------------------------------
  // Gets the title of the media.
  // Preconditions: None.
  // Postconditions: None.
  // Return: Returns title of media.
  // --------------------------------------------------------------------------
  string getTitle();

  // ---------------------------- getMediaTypeAbbrev --------------------------
  // Gets the abbrevation of the type of media.
  // Preconditions: None.
  // Postconditions: None.
  // Return: Returns abbrevation of the type of media.
  // --------------------------------------------------------------------------
  char getMediaTypeAbbrev();

  // ---------------------------- setTitle ------------------------------------
  // Sets the title of the media.
  // Preconditions: None.
  // Postconditions: This media now has a title.
  // Parameter: title - The title of the media.
  // --------------------------------------------------------------------------
  void setTitle(string title);

  // ---------------------------- setYearReleased -----------------------------
  // Sets the year media was released.
  // Preconditions: None.
  // Postconditions: This media now has a release year.
  // Parameter: yearReleased - The year the media was released.
  // --------------------------------------------------------------------------
  void setYearReleased(int yearReleased);

  // ---------------------------- setMediaTypeAbbrev --------------------------
  // Sets the media type to an abbrevation.
  // Preconditions: None.
  // Postconditions: This media now has a media type.
  // Parameter: mediaTypeAbbrev - The abbrevation of the type of media.
  // --------------------------------------------------------------------------
  void setMediaTypeAbbrev(char mediaTypeAbbrev);

protected:
  string m_title;    // Title of media
  int m_yearReleased;     // Year media was released
  char m_mediaTypeAbbrev; // The symbol for the type of media
};

#endif // !IMEDIA_

