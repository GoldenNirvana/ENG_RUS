#include "Utilities.hpp"

std::ostream &operator<<(std::ostream &out, std::set<std::string> &set)
{
  for (auto &item: set)
  {
    out << item << ' ';
  }
  out << '\n';
  return out;
}
