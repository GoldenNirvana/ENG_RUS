#ifndef RGR_ENG_RUS_DICTIONARY_HPP
#define RGR_ENG_RUS_DICTIONARY_HPP

#include <map>
#include <set>
#include <memory>
#include <ostream>

using map_iter = std::map<std::string, std::unique_ptr<std::set<std::string>>>::iterator;
using const_map_iter = std::map<std::string, std::unique_ptr<std::set<std::string>>>::const_iterator;

using set_iter = std::set<std::string>::iterator;
using const_set_iter = std::set<std::string>::const_iterator;

class Dictionary
{
public:
  Dictionary() = default;

  bool insert(const std::string &word, const std::string &translate);
  const_map_iter search(const std::string &word) const;
  bool deleteWord(const std::string &word);

  void printDictionary(std::ostream &out);
  void printByOrder(std::ostream &out);
  size_t size();
  const std::string &findWord(char letter) const;
  void addWordsFromAnotherDictionary(const Dictionary &dictionary);
  // todo 6?

private:
  std::map<std::string, std::unique_ptr<std::set<std::string>>> dictionary_;
};


#endif
