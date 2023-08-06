#include <iostream>

int get_change(int m) {
  int D[] = {10, 5, 1};
  int n  = 0, i = 0;
  while (m > 0)
  {
    if (D[i] <= m)
    {
      m -= D[i];
      n++;
    }
    else
    {
      i++;    
    }
  }
  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
