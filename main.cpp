#include "originalstore.h"
#include <fstream>
#include <iostream>
#include <string>

int main(void)
{

  // Opens movie file
  std::string moviesFile = "data4movies.txt";
  std::ifstream inputFileMovies(moviesFile.c_str());
  if (!inputFileMovies)
  {
    std::cout << "File could not be opened: " << moviesFile << std::endl;
    return 1;
  }

  // Opens customer file
  std::string customerFile = "data4customers.txt";
  std::ifstream inputFileCustomers(customerFile.c_str());
  if (!inputFileCustomers)
  {
    std::cout << "File could not be opened: " << customerFile << std::endl;
    return 1;
  }

  // Opens command file
  std::string commandFile = "data4commands.txt";
  std::ifstream inputFileCommands(commandFile.c_str());
  if (!inputFileCommands)
  {
    std::cout << "File could not be opened: " << commandFile << std::endl;
    return 1;
  }


  // Builds and run a particular instance of a store
  IStore* store;
  store = new OriginalStore;
  store->buildStore(inputFileCustomers, inputFileMovies);
  store->runStore(inputFileCommands);

  delete store;
  store = NULL;

  return 0;
}