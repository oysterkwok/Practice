#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, game = 0;
  cin >> n;
  while (n > 0) {
    game ++;
    vector<int> si;
    for (int i = 0; i < n; i ++) {
      int s;
      cin >> s;
      si.push_back(s);
    }
    cout << "Game " << game << ":\n";
    bool is_done = false;
    while (!is_done) {
      is_done = true;
      int strong = 0, weak = 0;
      vector<int> sc, gc;
      sc.resize(10, 0);
      gc.resize(10, 0);
      for (int i = 0; i < n; i ++) {
        int g;
        cin >> g;
        if (is_done && g > 0) {
          is_done = false;
        }
        if (g == si[i]) {
          strong ++;
        }
        else {
          sc[si[i]] ++;
          gc[g] ++;
        }
      }
      for (int i = 1; i < 10; i ++) {
        weak += min(sc[i], gc[i]);
      }
      if (!is_done) {
        cout << "    (" << strong << "," << weak << ")\n";
      }
    }
    cin >> n;
  }
  return 0;
}

