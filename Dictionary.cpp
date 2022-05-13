#include "Dictionary.hpp"
#include <iterator>
#include "Utilities.hpp"

bool Dictionary::insert(const std::string &word, const std::string &translate)
{
  auto iterator = dictionary_.find(word);
  if (iterator != dictionary_.end())
  {
    iterator->second->insert(translate);
    return true;
  }
  std::set<std::string> set;
  std::unique_ptr<std::set<std::string>> ptr = std::make_unique<std::set<std::string>>(set);
  ptr->insert(translate);
  std::pair<std::string, std::unique_ptr<std::set<std::string>>> pair = std::make_pair(word, std::move(ptr));
  dictionary_.insert(std::move(pair));
  return true;
  //todo возможно стоит сделать метод void, раз мапа сама отбрасывает повторяющие элементы и не смысла возвращать true
}

std::map<std::string, std::unique_ptr<std::set<std::string>>>::const_iterator
Dictionary::search(const std::string &word) const
{
  //todo уверен ты справишься
}

bool Dictionary::deleteWord(const std::string &word)
{
  auto iter = dictionary_.find(word);
  if (iter != dictionary_.end())
  {
    dictionary_.erase(word);
    return true;
  }
  return false;
}

void Dictionary::printDictionary(std::ostream &out)
{
  for (auto &item: dictionary_)
  {
    out << item.first << '\n';
    out << *item.second;
  }
}

void Dictionary::printByOrder(std::ostream &out)
{
  // todo сначала надо придумать что значит по порядку вообще
}

size_t Dictionary::size()
{
  return dictionary_.size();
}

const std::string &Dictionary::findWord(char letter) const
{
  for (auto &item: dictionary_)
  {
    if (item.first[0] == letter)
    {
      return item.first;
    }
  }
}

void Dictionary::addWordsFromAnotherDictionary(const Dictionary &dictionary)
{
 // todo эта штука тоже не сложная должна быть, раз stl юзаем, (мне было лень её писать пока, но думаю тут как и везде легко)
}


