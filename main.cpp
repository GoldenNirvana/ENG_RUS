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
    dictionary.insert("cat", "кошка");
    dictionary.insert("field", "поле");
    dictionary.insert("car", "машина");
    dictionary.insert("house", "здание");
    dictionary.insert("cat", "кисонька");
    dictionary.insert("cat", "кот");
    dictionary.insert("road", "путь");
    dictionary.insert("house", "дом");
    dictionary.insert("road", "дорога");


    Dictionary dictionary1;
    dictionary1.insert("dog", "псина");
    dictionary1.insert("dog", "собачка");
    dictionary1.insert("dog", "псина");


    std::vector<Dictionary> base;
    base.push_back(std::move(dictionary));
    base.push_back(std::move(dictionary1));
    Dictionary dictionary2 = commonDictionary(base);

    int count;
    std::cin >> count;
    int index = 0;
    std::vector<Dictionary> myDictionary;
    while (count--)
    {
      myDictionary.push_back(std::move(base[index++]));
    }
    Dictionary result = commonDictionary(myDictionary);
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what();
  }
  return 0;
}