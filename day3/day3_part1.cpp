#include <bits/stdc++.h>

int main()
{
  std::ifstream input("day3_input.txt");
  std::string line;
  std::regex mul_regex("mul\\(\\d+,\\d+\\)");

  long sum_of_products = 0;

  while(std::getline(input, line))
  {
    auto mul_ops_begin = std::sregex_iterator(line.begin(), line.end(), mul_regex);
    auto mul_ops_end   = std::sregex_iterator();

    for (std::sregex_iterator iter = mul_ops_begin; iter != mul_ops_end; ++iter)
    {
      std::string mul_op = (*iter).str();
      std::stringstream mul_op_ss(mul_op);
      char c;
      int num1, num2;
      mul_op_ss >> c >> c >> c >> c >> num1 >> c >> num2 >> c;
      
      sum_of_products += num1 * num2;
    }
  }

  std::cout << "sum of products: " << sum_of_products << std::endl;

  input.close();
  return 0;
}
