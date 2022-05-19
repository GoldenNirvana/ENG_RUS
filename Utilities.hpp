#ifndef RGR_ENG_RUS_UTILITIES_HPP
#define RGR_ENG_RUS_UTILITIES_HPP

#include <iostream>
#include <set>
#include <vector>
#include "Dictionary.hpp"

Dictionary doCompare(const Dictionary& curr, const Dictionary& next, Dictionary& temp);
Dictionary commonDictionary(std::vector<Dictionary> &common);
Dictionary makeFromUniqueWords(const Dictionary& d1, const Dictionary& d2);

std::ostream& operator<<(std::ostream& out, std::set<std::string>& set);

#endif

