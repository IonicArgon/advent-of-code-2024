#include <bits/stdc++.h>
#include <ranges>

int main()
{
  std::ifstream input("day1_input.txt");

  std::string line;
  std::string_view delim = "   ";
  std::vector<int> list1 = {};
  std::vector<int> list2 = {};

  while (std::getline(input, line))
  {
    auto split = line | std::views::split(delim)
                      | std::views::transform([](auto rng) {
                        auto str = std::string(&*rng.begin(), std::ranges::distance(rng));
                        return std::stoi(str);
                      });
    list1.push_back(*split.begin());
    list2.push_back(*std::next(split.begin()));
  }

  std::ranges::sort(list1);
  std::ranges::sort(list2);

  int total_distance = std::ranges::fold_left(
    std::views::iota(0, (int)list1.size())
    | std::views::transform([&list1, &list2](int i) {
      return std::abs(list1[i] - list2[i]);
    }), 
    0, std::plus<int>()
  );

  std::cout << "total distance: " << total_distance << std::endl;
  input.close();
  return 0;
}
