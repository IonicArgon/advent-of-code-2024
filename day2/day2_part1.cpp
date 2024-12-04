#include <bits/stdc++.h>

int main()
{
  std::ifstream input("day2_input.txt");

  int safe_reports = 0;
  std::vector<int> report;

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
      return a - b;
    });
    bool strictly_increasing_or_decreasing = std::ranges::all_of(differences, [](int i){ return i > 0; }) ||
                                             std::ranges::all_of(differences, [](int i){ return i < 0; });
    bool changes_within_range = std::ranges::all_of(differences, [](int i){ return std::abs(i) <= 3 && std::abs(i) >= 1; });
    if (strictly_increasing_or_decreasing && changes_within_range) {
      ++safe_reports;
    }

    report.clear();
  }

  std::cout << "safe reports: " << safe_reports << std::endl;
  input.close();
  return 0;
}