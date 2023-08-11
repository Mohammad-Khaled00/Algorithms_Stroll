#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

/*bool IsBetter_V1(string number1,string number2){
    while (!number1.empty() && !number2.empty()) {
      if (number1.front() == number2.front()) {
          // compare the next character
        if (number2.length() == 1 && number1.length() > 1)
          number1.erase(0, 1);
        else if (number1.length() == 1 && number2.length() > 1)
          number2.erase(0, 1);
        else if (number1.length() > 1 && number2.length() > 1)
        {
          number1.erase(0, 1);
          number2.erase(0, 1);
        }  
        else
          //return number1.compare(number2) > 0;
          return number1+number2 > number2+number1;
      } 
      else 
        return number1+number2 > number2+number1;
  }
  return false;
}*/

bool IsBetter_V2(string number1,string number2){
    return number1+number2 > number2+number1;
}

string largest_number(vector<string> a) {
  string Salary = "";
  std::sort(a.begin(), a.end(), IsBetter_V2);
  for (string number : a) {
    Salary.append(number);
  }
  return Salary;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
