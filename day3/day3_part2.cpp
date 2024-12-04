#include <bits/stdc++.h>

int main()
{
  std::ifstream input("day3_input.txt");
  std::string line;
  std::regex op_regex("mul\\(\\d+,\\d+\\)|do\\(\\)|don't\\(\\)");

  long sum_of_products = 0;
  bool is_multiplying = true;

  while(std::getline(input, line))
  {
    auto ops_begin = std::sregex_iterator(line.begin(), line.end(), op_regex);
    auto ops_end   = std::sregex_iterator();

    for (std::sregex_iterator iter = ops_begin; iter != ops_end; ++iter)
    {
      std::string op = (*iter).str();
      
      if (op == "do()") 
      {
        is_multiplying = true;
        continue;
      } else if (op == "don't()")
      {
        is_multiplying = false;
        continue;
      }

      if (is_multiplying) {
        std::stringstream op_ss(op);

        char c;
        int num1, num2;
        op_ss >> c >> c >> c >> c >> num1 >> c >> num2 >> c;

        sum_of_products += num1 * num2;
      }
    }
  }

  std::cout << "sum of products: " << sum_of_products << std::endl;

  input.close();
  return 0;
}
