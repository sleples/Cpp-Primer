#include <string>
#include <deque>
#include <iostream>

int main() {
  std::deque<std::string> in;
  std::string word;
  while (std::cin >> word)
    in.push_back(word);
  for (auto i = in.cbegin(); i != in.cend(); ++i)
    std::cout << *i << std::endl;
}