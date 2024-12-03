#include <bits/stdc++.h>

int main() 
{
  std::ifstream input("day1_input.txt");

  std::string line;
  std::vector<int> list1 = {};
  std::vector<int> list2 = {};

  while (std::getline(input, line))
  {
    int delim_pos = line.find("   ");
    std::string list1_elem = line.substr(0, delim_pos);
    std::string list2_elem = line.substr(delim_pos);
    list1.push_back(std::stoi(list1_elem));
    list2.push_back(std::stoi(list2_elem));
  }

  std::sort(list1.begin(), list1.end());
  std::sort(list2.begin(), list2.end());

  int total_distance = std::transform_reduce(
    list1.begin(), list1.end(), list2.begin(), 0, std::plus<int>(), 
    [](int a, int b) { return std::abs(a - b); }
  );

  std::cout << "total distance: " << total_distance << std::endl;
  input.close();
  return 0;
}
