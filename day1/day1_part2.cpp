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
    list1.push_back(std::stoi(line.substr(0, delim_pos)));
    list2.push_back(std::stoi(line.substr(delim_pos + 3)));
  }

  std::unordered_map<int, std::pair<int, int>> similarity_scores = {};
  for (const auto& id : list1)
  {
    if (similarity_scores.contains(id)) 
    {
      auto previous_pair = similarity_scores.at(id);
      similarity_scores.at(id) = std::make_pair(
        previous_pair.first, 
        previous_pair.second + previous_pair.first
      );
    }

    int instances_in_second = std::count(list2.begin(), list2.end(), id);
    similarity_scores.insert({
      id, 
      std::make_pair(id * instances_in_second, id * instances_in_second)
    });
  }

  int total_similarity_score = std::accumulate(similarity_scores.begin(), similarity_scores.end(), 0, 
    [](int acc, const std::pair<int, std::pair<int, int>>& pair) {
      return acc + pair.second.second;
    }
  );

  std::cout << "total similarity score: " << total_similarity_score << std::endl;
  input.close();
  return 0;
}
