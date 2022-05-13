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
}

const_map_iter &Dictionary::search(const std::string &word) const
{

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
  // todo
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

}


