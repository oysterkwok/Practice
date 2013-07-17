#include <iostream>
#include <vector>

using namespace std;

vector<int> x, y;

int main() {
  int n;
  cin >> n;
  while (n > 0) {
    x.clear();
    y.clear();
    x.resize(n*2);
    y.resize(n*2);
    for (int i = 0; i < n*2; i ++) {
      cin >> x[i] >> y[i];
    }
    bool found = false;
    for (int a = -500; a <= 500; a ++) {
      if (found) break;
      for (int b = -500; b <= 500; b ++) {
        int pos = 0;
        int neg = 0;
        for (int i = 0; i < n*2; i ++) {
          if (a*x[i] + b*y[i] > 0) {
            pos ++;
          }
          if (a*x[i] + b*y[i] < 0) {
            neg ++;
          }
        }
        if (pos == n && neg == n) {
          cout << a << ' ' << b << '\n';
          found = true;
          break;
        }
      }
    } 
    cin >> n;
  }
  return 0;
}
