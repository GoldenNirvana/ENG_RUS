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

//ДЕЛАТЬ ДЛЯ 2 ПЕРВЫХ СЛОВАРЬ ОТДЕЛЬНО, А ПОТОМ ПЕРЕДАВАТЬ 1 СЛЕДУЮЩИЙ И ПОСТЕПЕННО ФОРМИРУЮЩИЙСЯ ОБЩИЙ СЛОВАРЬ
//НУЖНА ДРУГАЯ Функция после первого и второго словаря
Dictionary commonDictionary(std::vector<Dictionary> &common)
{
  Dictionary result;
  for (const auto &item: common[0])
  {
    result.insert(item);
  }

  for (const auto &item: common)       // Идём по всем словарям
  {
    for (const auto &item1: item)        // Идём по всем словам одного словаря
    {
      if (result.search(item1.first) ==
          result.end())   // Если этого слова нет в начальном словаре -> слова не повторяются -> удаляем
      {
        result.deleteWord(item1.first);
      }
      else
      {
        // тут получается что слово есть во всех словарях до текущего включительно,
        // и ты тут что-то хотела сделать с переводами, но я не очень понял что
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
