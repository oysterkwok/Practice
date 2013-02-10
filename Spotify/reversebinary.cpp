#include <iostream>
#include <vector>

using namespace std;

int main() {
  unsigned long num;
  cin >> num;
  vector<bool> bin_form;
  while (num > 0) {
    bin_form.push_back(num % 2);
    num /= 2;
  }
  unsigned long out = 0;
  unsigned long mult = 1;
  for (int i = 0; i < bin_form.size(); i ++) {
    if (bin_form[bin_form.size()-i-1]) {
      out += mult;
    }
    mult <<= 1;
  }
  cout << out << '\n';
  return 0;
}
