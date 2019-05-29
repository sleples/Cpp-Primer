#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <iostream>

std::map<std::string, std::string> buildMap(std::ifstream &map_file)
{
  std::map<std::string, std::string> trans_map;
  std::string key;
  std::string val;
  while (map_file >> key && getline(map_file, val))
    if (val.size() > 1)
      trans_map[key] = val.substr(1);
    else
      throw std::runtime_error("no rule for " + key);
  return trans_map;
}

const std::string &transform(const std::string &s, const std::map<std::string, std::string> &m)
{
  auto map_it = m.find(s);
  if (map_it != m.cend())
    return map_it->second;
    else
      return s;
}

void word_transform(std::ifstream &map_file, std::ifstream &input)
{
  auto trans_map = buildMap(map_file);
  std::string text;
  while (getline(input, text))
  {
    std::istringstream stream(text);
    std::string word;
    bool firstword = true;
    while (stream >> word)
    {
      if (firstword)
        firstword = false;
      else
        std::cout << " ";
      std::cout << transform(word, trans_map);
    }
  }
  std::cout << std::endl;
}

int main()
{
}