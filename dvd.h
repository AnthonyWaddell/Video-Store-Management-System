// ---------------------------- dvd.h ----------------------------------------
// Name and Section: Ryan Harlich, Rio Zhu, Anthony Waddell, Chris Salazar 
//                   CSS 343 B
// Created: February 17, 2018
// Date of Last Modification: February 23, 2018
// ---------------------------------------------------------------------------
// Purpose - An DVD interface. Includes things such as comedy, classics,
// drama.
// ---------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions: None.
// ---------------------------------------------------------------------------

#ifndef DVD_
#define DVD_

#include "imedia.h"
#include <iostream>
#include <fstream> // For ifstream
using namespace std;

class DVD : public IMedia
{
public:
  // ---------------------------- DVD -----------------------------------------
  // A default constructor that sets the media type abbrevation to 'D' for DVD.
  // Preconditions: None.
  // Postconditions: None.
  // --------------------------------------------------------------------------
  DVD();

  // ---------------------------- ~DVD ----------------------------------------
  // An empty virtual destructor for extensibility.
  // Preconditions: None.
  // Postconditions: None.
  // --------------------------------------------------------------------------
  virtual ~DVD();

  // ---------------------------- display -------------------------------------
  // Displays DVD information.
  // Preconditions: None.
  // Postconditions: outStream contains DVD information.
  // Parameter: outStream - A out stream for the display.
  // --------------------------------------------------------------------------
  virtual void display(std::ostream& outStream) const = 0;

  // ---------------------------- genDisplay ----------------------------------
  // Generates the display information into a string.
  // Preconditions: None.
  // Postconditions: genDisplayString contains DVD information.
  // Parameter: genDisplayString - A string that will contain the DVD's
  // information after the method executes.
  // --------------------------------------------------------------------------
  virtual void genDisplay(std::string& genDisplayString) = 0;

  // ---------------------------- displaySearchKey ----------------------------
  // Displays the search key information of the DVD.
  // Preconditions: None.
  // Postconditions: outStream contains DVD search key information.
  // Parameter: outStream - A out stream for the display.
  // --------------------------------------------------------------------------
  virtual void displaySearchKey(std::ostream& outStream) = 0;

  // ---------------------------- genSearchKey --------------------------------
  // Generates an DVD that only contains its search key information.
  // Preconditions: None.
  // Postconditions: This DVD has its search key information updated. 
  // ifStream will be at the end of its line.
  // Parameter: inputFile - A file the contains the search key of the DVD.
  // --------------------------------------------------------------------------
  virtual void genSearchKey(std::ifstream& inputFile) = 0;

  // ---------------------------- compareSearchKey ----------------------------
  // Detects if DVD is the same purely based of its search key information.
  // Preconditions: itemPtr is a type of DVD.
  // Postconditions: None.
  // Parameter: itemPtr - Item to compare against to see if it is the same
  // item based of a search key information.
  // Return: Returns true if item is same as item with search key information
  // --------------------------------------------------------------------------
  virtual bool compareSearchKey(IItem* itemPtr) = 0;

  // ---------------------------- genCopy -------------------------------------
  // Generates a copy of an DVD so all of this DVD fields are the same as
  // the parameters items fields.
  // Preconditions: itemPtr is a type of DVD.
  // Postconditions: This DVD contains the same fields as the parameter item.
  // Parameter: itemPtr - Item to copy its member variables.
  // --------------------------------------------------------------------------
  virtual void genCopy(IItem* itemPtr) = 0;

  // ---------------------------- compare -------------------------------------
  // Compares two DVDs determining if should go ahead of DVD, is same 
  // DVD, or goes after DVD.
  // Preconditions: itemPtr is a type of DVD.
  // Postconditions: None.
  // Parameter: itemPtr - An item to compare against.
  // Return: Returns -1 for goes before, 0 forst same, and 1 for goes after.
  // --------------------------------------------------------------------------
  virtual int compare(IItem* itemPtr) = 0;

  // ---------------------------- buildDVD ------------------------------------
  // Builds a DVD by setting all of the DVDs data members from an input file
  // that contains a line of information about a particular DVD.
  // Preconditions: genre is a valid movie genre and inputFileInventory is
  // formatted properly.
  // Postconditions: This DVD is built and contains all its proper information.
  // Parameter: genre - An genre of this particular DVD.
  // inputFileInventory - a file that contains the inventory and one line
  // that has a DVDs information.
  // --------------------------------------------------------------------------
  virtual void buildDVD(char genre, std::ifstream& inputFileInventory) = 0;
  
  // ---------------------------- operator== ----------------------------------
  // Compares if two DVDs are the same.
  // Preconditions: itemPtr is a type of DVD.
  // Postconditions: None.
  // Parameter: itemPtr - An item to compare against.
  // Return: Returns true if DVD is the same, false otherwise.
  // --------------------------------------------------------------------------
  virtual bool operator==(IItem* itemPtr) = 0;

  // ---------------------------- getGenre ------------------------------------
  // Returns genre abbrevation of DVD.
  // Preconditions: None.
  // Postconditions: None.
  // Return: Returns the genre abbrevation of the DVD.
  // --------------------------------------------------------------------------
  char getGenre();

  // ---------------------------- getDirector ---------------------------------
  // Returns director of DVD.
  // Preconditions: None.
  // Postconditions: None.
  // Return: Returns the director of the DVD.
  // --------------------------------------------------------------------------
  string getDirector();

  // ---------------------------- setDirector ---------------------------------
  // Sets the director of the DVD.
  // Preconditions: None.
  // Postconditions: None.
  // Parameter: director - Director of DVD.
  // --------------------------------------------------------------------------
  void setDirector(string director);

  // ---------------------------- setDirector ---------------------------------
  // Sets the genre abbrevation of the DVD.
  // Preconditions: None.
  // Postconditions: None.
  // Parameter: genreAbbrev - Genre abbrevation of DVD.
  // --------------------------------------------------------------------------
  void setGenreAbbrev(char genreAbbrev);

protected:
  // ---------------------------- compareByGenre ------------------------------
  // Compares DVDs by genre. Compares in the order that larger genre 
  // abbrevation goes first (e.g., F,D, then C).
  // Preconditions: None.
  // Postconditions: None.
  // Parameter: genre - Genre of other of DVD to compare.
  // Return: Returns -1 if DVD to compare against genre is greater than this
  // DVD, 0 if the same genre, 1 if less than this DVD.
  // --------------------------------------------------------------------------
  int compareByGenre(char genre);

protected:
  // ---------------------------- compareDVD ----------------------------------
  // Compares DVDs by their sorting order.
  // Preconditions: None.
  // Postconditions: None.
  // Parameter: dvdPtr - The DVD to compare against.
  // Return: Returns -1 if dvdPtr goes ahead, 0 if the same, and 1 if dvdPtr
  // goes after.
  // --------------------------------------------------------------------------
  virtual int compareDVD(DVD* dvdPtr) = 0;

  string m_director; // The director of the DVD
  char m_genreAbbrev;     // The genre abbrevation of the DVD
};

#endif // !DVD_
