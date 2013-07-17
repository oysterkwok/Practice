#include <iostream>

using namespace std;

int main() {
  int e[20][20];
  int n, tn = 0;
  while (cin >> n) {
    tn ++;
    cout << "Test Set #" << tn << '\n';
    for (int i = 0; i < 20; i ++) {
      for (int j = 0; j < 20; j ++) {
        e[i][j] = 500;
      }
      e[i][i] = 0;
    }
    for (int i = 0; i < n; i ++) {
      int m;
      cin >> m;
      e[0][m-1] = 1;
      e[m-1][0] = 1;
    }
    for (int i = 1; i < 19; i ++) {
      cin >> n;
      for (int j = 0; j < n; j ++) {
        int m;
        cin >> m;
        e[i][m-1] = 1;
        e[m-1][i] = 1;
      }
    }
    bool done = false;
    while (!done) {
      done = true;
      for (int i = 0; i < 20; i ++) {
        for (int j = 0; j < 20; j ++) {
          for (int k = 0; k < 20; k ++) {
            if (e[i][j]+e[j][k] < e[i][k]) {
              e[i][k] = e[i][j] + e[j][k];
              done = false;
            }
          }
        }
      }
    }
    cin >> n;
    for (int i = 0; i < n; i ++) {
      int x, y;
      cin >> x >> y;
      if (x < 10) {
        cout << ' ';
      }
      cout << x << " to ";
      if (y < 10) {
        cout << ' ';
      }
      cout << y << ": " << e[x-1][y-1] << '\n';
    }
    cout << '\n';
  }
}
