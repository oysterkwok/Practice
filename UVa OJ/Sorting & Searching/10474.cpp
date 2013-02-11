#include <iostream>

using namespace std;

int main() {
  int x, y, cn = 0;
  cin >> x >> y;
  while (x > 0 || y > 0) {
    cn ++;
    cout << "CASE# " << cn << ":\n";
    int pos[10005];
    for (int i = 0; i <= 10001; i ++) {
      pos[i] = 0;
    }
    for (int i = 0; i < x; i ++) {
      int z;
      cin >> z;
      pos[z] ++;
    }
    
    for (int i = 1; i <= 10001; i ++) {
      pos[i] += pos[i-1];
    }

    for (int i = 0; i < y; i ++) {
      int z;
      cin >> z;
      if (pos[z-1] == pos[z]) {
        cout << z << " not found\n";
      }
      else {
        cout << z << " found at " << pos[z-1]+1 << '\n';
      }
    }
    cin >> x >> y;
  }
  return 0;
}
