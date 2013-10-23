#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n;i ++) {
    string x, y, z;
    cin >> x >> y;
    int hx=0, hy=0, hz=0;
    while (hx < x.size() || hy < y.size()) {
      if (x[hx] == 'p' && y[hy] == 'p') {
        z += 'p';
        hx ++;
        hy ++;
        continue;
      }
      if (x[hx] == 'f') {
        z += 'f';
        hx ++;
        int count = 1;
        while (count > 0) {
          if (y[hy] == 'p') {
            count += 3;
          }
          else {
            count --;
          }
          hy ++;
        }
        continue;
      }
      if (y[hy] == 'f') {
        z += 'f';
        hy ++;
        int count = 1;
        while (count > 0) {
          if (x[hx] == 'p') {
            count += 3;
          }
          else {
            count --;
          }
          hx ++;
        }
        continue;
      }
      if (x[hx] == 'e') {
        hx ++;
        int count = 1;
        while (count > 0) {
          z += y[hy];
          if (y[hy] == 'p') {
            count += 3;
          }
          else {
            count --;
          }
          hy ++;
        }
        continue;
      }
      if (y[hy] == 'e') {
        hy ++;
        int count = 1;
        while (count > 0) {
          z += x[hx];
          if (x[hx] == 'p') {
            count += 3;
          }
          else {
            count --;
          }
          hx ++;
        }
      }
    }
    int sum = 0;
    int depth = 0;
    vector<int> counts;
    counts.resize(10, 0);
    while (hz < z.size()) {
      if (z[hz] == 'f') {
        sum += 1024 >> (depth*2);
        counts[depth] ++;
      }
      if (z[hz] == 'p') {
        counts[depth] ++;
        depth ++;
        counts[depth] = 0;
      }
      if (z[hz] == 'e') {
        counts[depth] ++;
      }
      if (counts[depth] >= 4) {
        depth --;
      }
      hz ++;
    }
    cout << "There are " << sum << " black pixels.\n";
  }
}
