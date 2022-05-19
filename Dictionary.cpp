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
  std::shared_ptr<std::set<std::string>> ptr = std::make_shared<std::set<std::string>>(set);
  ptr->insert(translate);
  Item pair = std::make_pair(word, ptr);
  dictionary_.insert(pair);
  return true;
}

bool Dictionary::insert(const Item &item)
{
  for (const auto &item1: *item.second)
  {
    this->insert(item.first, item1);
  }
  return true;
}

std::map<std::string, std::shared_ptr<std::set<std::string>>>::const_iterator
Dictionary::search(const std::string &word) const
{
  return dictionary_.find(word);
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

void Dictionary::addWordsFromAnother(const Dictionary& dictionary)
{
  for (auto &word: dictionary.dictionary_)
  {
    for (const auto &translate: *word.second)
    {
      this->insert(word.first, translate);
    }
  }
}

const std::map<std::string, std::shared_ptr<std::set<std::string>>> &Dictionary::getDictionary() const
{
  return dictionary_;
}
std::map<std::string, std::shared_ptr<std::set<std::string>>>::const_iterator Dictionary::begin() const
{
  return dictionary_.begin();
}

std::map<std::string, std::shared_ptr<std::set<std::string>>>::const_iterator Dictionary::end() const
{
  return dictionary_.end();
}



































/*#include "Dictionary.hpp"
#include <iterator>
#include <algorithm>
#include "Utilities.hpp"

bool Dictionary::insert(const std::string& word, const std::string& translate)
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
  // set.insert(translate); ������
  std::pair<std::string, std::unique_ptr<std::set<std::string>>> pair = std::make_pair(word, std::move(ptr));
  dictionary_.insert(std::move(pair));
  return true;
  //todo �������� ����� ������� ����� void, ��� ���� ���� ����������� ����������� �������� � �� ������ ���������� true
}

std::map<std::string, std::unique_ptr<std::set<std::string>>>::const_iterator
Dictionary::search(const std::string& word) const
{
  return dictionary_.find(word);
}

bool Dictionary::deleteWord(const std::string& word)
{
  auto iter = dictionary_.find(word);
  if (iter != dictionary_.end())
  {
    dictionary_.erase(word);
    return true;
  }
  return false;
}

void Dictionary::printDictionary(std::ostream& out)
{
  for (auto& item : dictionary_)
  {
    out << item.first << '\n';
    out << *item.second;
  }
}

//void Dictionary::printByOrder(std::ostream& out)
//{
//  std::sort(dictionary_.begin(), dictionary_.end());
//  printDictionary(out);
//}

size_t Dictionary::size()
{
  return dictionary_.size();
}

const std::string& Dictionary::findWord(char letter,std::ostream& out) const
{
  for (auto& item : dictionary_)
  {
    if (item.first[0] == letter)
    {
      out << item.first;
    }
  }
}

void Dictionary::printWithUniqueTranslate(std::ostream& out) const
{
  for (auto &item: dictionary_)
  {
    if(item.second->size() == 1)
    {
      out << item.first;
    }
  }
}


void Dictionary::addWordsFromAnother(const Dictionary& dictionary)
{
  for (auto &word: dictionary.dictionary_)
  {
    for (const auto &translate: *word.second)
    {
      this->insert(word.first, translate);
    }
  }
}

*//*
const std::map<std::string, std::unique_ptr<std::set<std::string>>> &Dictionary::getDictionary() const
{
  return dictionary_;
}

bool Dictionary::insert(myItem& item)
{
  for (const auto &translate: *item.second)
  {
    this->insert(item.first, translate);
  }
}
*/
