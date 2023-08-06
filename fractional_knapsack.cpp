#include <iostream>
#include <vector>

using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  int weight = 0;
  double best = 0;
  int index = 0;
  for (int i = 0; i < weights.size(); i++)
  {
    weight += weights[i];
    if (values[i]/weights[i] > best)
    {
      best = values[i]/weights[i];
      index = i;
    }
  }

  if (capacity == 0 || weight == 0)
  {
    return 0;
  }
  double amount = std::min(capacity, weights[index]);
  capacity -= amount;
  value = values[index] * (amount / weights[index]);
  values.erase(values.begin() + index);
  weights.erase(weights.begin() + index);
  return value + get_optimal_value(capacity, weights, values);;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
