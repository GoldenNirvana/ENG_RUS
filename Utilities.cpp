#include "Utilities.hpp"
#include "Dictionary.hpp"

std::ostream &operator<<(std::ostream &out, std::set<std::string> &set)
{
  for (auto &item: set)
  {
    out << item << ' ';
  }
  out << '\n';
  return out;
}

//СДЕЛАТЬ ИНТЕРФЕЙС И ДОБАВЛЕНИЕ СЛОВ ИЗ ПОТОКА!

//ХОЧУ ПЕРЕДАТЬ СЮДА ИТЕРАТОРЫ НА ПАРУ, НА ДАННОЕ СЛОВО В ОБОИХ СЛОВАРЯХ. ДЛЯ КАЖДОГО ЕГО ПЕРЕВОДА ИЗ ПЕРВОГО
//СЛОВАРЯ ДЕЛАЕМ FOR В FOR И ПРОВЕРЯЕМ, ЯВЛЯЮТСЯ ЛИ ПЕРЕВОДЫ ОДИНАКОВЫМИ.
//ЕСЛИ ТАК, ВСТАВЛЯЕМ В SET ДЛЯ МОЕГО СЛОВА ДАННЫЙ ПЕРЕВОД
//bool compareTranslates(std::map<std::string, std::unique_ptr<std::set<std::string>>>::const_iterator curr,
//                       Item& item, Dictionary& temp)
//{
//  for (const auto &temp2: curr->second)
//  {
//    if
//  }
//}

//Dictionary doCompare(const Dictionary &curr, const Dictionary &next, Dictionary &temp)
//{
//  for (const Item &item: next)
//  {
//    if (curr.search(item.first) == curr.end())
//    {
//      compareTranslates(*curr.search(item.first), item, temp);
//    }
//  }
//  temp.insert(item);
//}

Dictionary commonDictionary(std::vector<Dictionary> &common)
{
  Dictionary result;
  bool isCommon = false;

  for (const auto &dictionary: common)       // Идём по всем словарям
  {
    for (const auto &pair: dictionary)        // Берём каждое слово в словаре
    {
      for (const auto &item: common)        // С текущим словом опять идём по всем словарям
      {
        isCommon = true;
        if (item.search(pair.first) == item.end()) // Проверяем его наличие во всех остальных
        {
          isCommon = false;                   // Если хотя бы в одном словаре его нет -> слово не уникальное и его не будет добавлять в Result
          break;
        }
      }
      if (isCommon)         // если во всех нашлось это слово -> isCommon останется true и мы слово добавим в result
      {
        result.insert(pair);
      }
    }
  }
  return result;
}


Dictionary makeFromUniqueWords(const Dictionary &d1, const Dictionary &d2)
{
  Dictionary common;
  for (const Item &item: d1)
  {
    if (d2.search(item.first) == d2.end())
    {
      common.insert(item);
    }
  }
  for (const Item &item: d2)
  {
    if (d1.search(item.first) == d1.end())
    {
      common.insert(item);
    }
  }
  return common;
}
