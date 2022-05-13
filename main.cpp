#include <iostream>
#include "Dictionary.hpp"

int main()
{
  try
  {
    Dictionary dictionary;
    dictionary.insert("cat", "кошка");
    dictionary.insert("cat", "кошечка");
    dictionary.insert("cat", "киса");
    dictionary.insert("cat", "кисонька");

    dictionary.insert("dog", "псина");
    dictionary.insert("dog", "собачка");

    dicl

    dictionary.printDictionary(std::cout);

//  std::cout << dictionary.findWord('d');
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what();
  }
  return 0;
}
