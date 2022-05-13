#include <iostream>
#include "Dictionary.hpp"

int main()
{
  Dictionary dictionary;
  dictionary.insert("cat", "кошка");
  dictionary.insert("cat", "кошечка");
  dictionary.insert("cat", "киса");
  dictionary.insert("cat", "кисонька");

  dictionary.insert("dog", "псина");
  dictionary.insert("dog", "собачка");

  dictionary.printDictionary(std::cout);

//  std::cout << dictionary.findWord('d');

  return 0;
}
