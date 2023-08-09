#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  int sum = 0, i = 0;;
  while (sum != n)
  {
    i++;
    if (sum + i <= n)
    {
      sum += i;
      summands.push_back(i);
    }
    else
    {
    sum -= summands.back();
    summands.pop_back();
    i--;
    }  
  }
  
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
