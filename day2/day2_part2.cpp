#include <bits/stdc++.h>

std::vector<std::vector<int>> permute_vector(std::vector<int> &vec)
{
  std::vector<std::vector<int>> permutations;
  for (int i = 0; i < vec.size(); ++i) {
    std::vector<int> dest = vec;
    dest.erase(dest.begin() + i);
    permutations.push_back(dest);
  }

  return permutations;
}

int main()
{
  std::ifstream input("day2_input.txt");

  int safe_reports = 0;
  std::vector<int> report;
  std::vector<std::vector<int>> failed_reports;

  std::string line;
  std::string_view delim = " ";
  while (std::getline(input, line))
  {
    auto split = line | std::views::split(delim)
                      | std::views::transform([](auto rng) {
                        auto str = std::string(&*rng.begin(), std::ranges::distance(rng));
                        return std::stoi(str);
                      });
    for (auto num : split) {
      report.push_back(num);
    }

    auto differences = report | std::views::adjacent_transform<2>([](int a, int b){
      return b - a;
    });

    bool strictly_increasing_or_decreasing = std::ranges::all_of(differences, [](int i){ return i > 0; }) ||
                                             std::ranges::all_of(differences, [](int i){ return i < 0; });
    bool changes_within_range = std::ranges::all_of(differences, [](int i){ return std::abs(i) <= 3 && std::abs(i) >= 1; });
    if (strictly_increasing_or_decreasing && changes_within_range) {
      ++safe_reports;
    } else {
      failed_reports.push_back(report);
    }

    report.clear();
  }

  for (auto report : failed_reports)
  {
    auto permutations = permute_vector(report);
    for (auto permutation : permutations)
    {
      auto differences = permutation | std::views::adjacent_transform<2>([](int a, int b) {
        return b - a;
      });
      bool strictly_increasing_or_decreasing = std::ranges::all_of(differences, [](int i){ return i > 0; }) ||
                                               std::ranges::all_of(differences, [](int i){ return i < 0; });
      bool changes_within_range = std::ranges::all_of(differences, [](int i){ return std::abs(i) <= 3 && std::abs(i) >= 1; });
      if (strictly_increasing_or_decreasing && changes_within_range) {
        ++safe_reports;
        break;
      }
    }
  }

  std::cout << "safe reports: " << safe_reports << std::endl;

  input.close();
  return 0;
}