#include <iostream>
#include <fstream>
#include <vector>
#include "Dictionary.hpp"
#include "Utilities.hpp"

int main()
{
//  shkroba::Dictionary d1("d1");
//  shkroba::Dictionary d2("d2");
//  shkroba::Dictionary d3("d3");
//  shkroba::Dictionary d4("d4");
//  shkroba::Dictionary d5("d5");

  std::ifstream fin("in.txt");
  std::vector<shkroba::Dictionary> vector = shkroba::createDictionariesFromFile(fin);
  for (const auto &item: vector)
  {
    item.printDictionary(std::cout);
  }
  int test = 1;

  try
  {
    // shkroba::createTestDictionaries(d1, d2, d3, d4, d5);
    //shkroba::testCommandSystem(d1, d2, d3, d4, d5);
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what();
  }
  return 0;
}
