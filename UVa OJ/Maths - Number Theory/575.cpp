#include<iostream>

using namespace std;

int main() {
  string n;
  cin >> n;
  while (n[0] != '0') {
    unsigned int result = 0;
    unsigned int mult = 1;
    for (int i = (int) n.size()-1; i >= 0; i --) {
      mult *= 2;
      result += (n[i]-'0') * (mult-1);
    }
    cout << result << '\n';
    cin >> n;
  }
}
