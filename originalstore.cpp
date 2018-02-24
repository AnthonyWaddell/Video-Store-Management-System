#include "originalstore.h"
#include <string.h>

using namespace std;
// --------------------------------------------------------------------------
//
// --------------------------------------------------------------------------
OriginalStore::~OriginalStore()
{
}

// --------------------------------------------------------------------------
//
// --------------------------------------------------------------------------
void OriginalStore::buildStore(std::ifstream & inputFileCustomers, std::ifstream & inputFileInventory)
{
	buildInventory(inputFileInventory);
	buildCustomers(inputFileCustomers);
}

// --------------------------------------------------------------------------
//
// --------------------------------------------------------------------------
void OriginalStore::buildCustomers(std::ifstream & inputFileCustomers)
{
	while (true)
	{
		if (inputFileCustomers.eof())
		{
			break;
		}
		int id;
		string first_name;
		string last_name;

		inputFileCustomers >> id;
		getline(inputFileCustomers, first_name, ' ');
		getline(inputFileCustomers, last_name, ' ');

		//Customer m_customer = new Customer(id, first_name, last_name);
	}
}

// --------------------------------------------------------------------------
//
// --------------------------------------------------------------------------
void OriginalStore::buildInventory(std::ifstream & inputFileInventory)
{
	DVD *dvd_ptr = NULL;
	char genre = ' ';
	string bad_data = "";

	while (true)
	{
		if (inputFileInventory.eof())
		{
			break;
		}
		inputFileInventory >> genre;

		dvd_ptr = DFactory::createDVD(genre);
		if (dvd_ptr == NULL)
		{
			cout << "Invalid data" << endl;
			getline(inputFileInventory, bad_data);
			continue;
		}
		else
		{
			// getline a bunch of stuff into dvd_ptr for all the valid data in the current string
			// add dvd_ptr to linked list
		}
	}
}
