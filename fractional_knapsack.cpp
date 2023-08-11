#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

/*double get_optimal_value_v1(int capacity, vector<int> weights, vector<int> values) {
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
  return value + get_optimal_value_v1(capacity, weights, values);
}*/

double get_optimal_value_v2(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  vector<std::pair<double, int>> v(weights.size());

  for (int i = 0; i < weights.size(); i++)
  {
    v[i] = {double(values[i]) / double(weights[i]), i};
  }
  sort(v.rbegin(), v.rend());

  for (int i = 0; i < weights.size() && capacity > 0; i++) {
    int index = v[i].second;
    double amount = std::min(capacity, weights[index]);
    capacity -= amount;
    value += amount * v[i].first;
  }
  return value;
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

  double optimal_value = get_optimal_value_v2(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
