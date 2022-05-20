#include <iostream>
#include <fstream>
#include <vector>
#include "Dictionary.hpp"
#include "Utilities.hpp"

int main()
{
  try
  {
    Dictionary dictionary;
    Dictionary dictionary1;
    Dictionary dictionary2;

    dictionary.insert("Cat", "Кошка");
    dictionary.insert("Cat", "Киса");
    dictionary.insert("Dog", "Собака");
    dictionary.insert("A", "AT");

    dictionary1.insert("Cat", "Киса");
    dictionary1.insert("Cat", "Кошка");
    dictionary1.insert("Cat", "Кисонька");
    dictionary1.insert("Dog", "Собака");
    dictionary1.insert("B", "BT");

    dictionary2.insert("Cat", "Кошка");
    dictionary2.insert("Cat", "Котя");
    dictionary2.insert("Cat", "Киса");
    dictionary2.insert("Dog", "Собака");
    dictionary2.insert("C", "CT");


    std::vector<Dictionary> base;
    base.push_back(dictionary);
    base.push_back(dictionary1);
    base.push_back(dictionary2);

    commonDictionary(base).printDictionary(std::cout);

  }
  catch (const std::exception &e)
  {
    std::cerr << e.what();
  }
  return 0;
}