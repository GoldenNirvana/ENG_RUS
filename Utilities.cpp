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

Dictionary commonDictionary(std::vector<Dictionary> &common)
{
  Dictionary result;
  bool isCommon;

  std::map<std::string, size_t> translates; // перевод и кол-во раз которое встретилось этого перевода

  Dictionary dictionary = *common.begin();
  for (const auto &pair: dictionary)        // Берём каждое слово в словаре
  {
    if (result.search(pair.first) != result.end())
    {
      continue;
    }
    isCommon = true;
    translates.clear();
    for (const auto &dictionarySecond: common)        // С текущим словом опять идём по всем словарям
    {
      if (dictionarySecond.search(pair.first) == dictionarySecond.end()) // Проверяем его наличие во всех остальных
      {
        isCommon = false;                   // Если хотя бы в одном словаре его нет -> слово не уникальное и его не будет добавлять в Result
        break;
      }
      else
      {
        Item item = *dictionarySecond.search(
          pair.first); // находим set в котором все переводы этого слова в данном словаре
        for (const auto &word: *item.second)   // вставляем все эти слова в наши переводы
        {
          translates[word]++;
        }
      }
    }
    if (isCommon)         // если во всех нашлось это слово -> isCommon останется true и мы слово добавим в result
    {
      std::set<std::string> set; // set в котором будут только общие слова
      for (const auto &translate: translates)
      {
        if (translate.second == common.size())
        {
          set.insert(translate.first);
        }
      }
      if (set.empty()) // Тут будем давать написать перевод если не встретилось ни одного общего
      {
        std::cout << "Write translate for " + pair.first << '\n';
        std::cout << "Write \"Exit\" to escape\n";
        std::string in;
        std::cin >> in;
        while (in != "Exit")
        {
          set.insert(in);
          std::cin >> in;
        }
      }
      std::shared_ptr<std::set<std::string>> sharedPtr = std::make_shared<std::set<std::string>>(set);
      result.insert({pair.first, sharedPtr});
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
