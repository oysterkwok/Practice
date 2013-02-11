#include <iostream>
#include <vector>

using namespace std;

int main() {
  string vowels = "AUEOI";
  string consonants = "JSBKTCLDMVNWFXGPYHQZR";
  int n;
  cin >> n;
  for (int i = 0; i < n; i ++) {
    int m;
    cin >> m;
    string result, rv, rc;
    int nv = (m+1) / 2;
    for (int j = 0; j < nv; j ++) {
      rv += vowels[j/21];
    }
    int nc = m - nv;
    for (int j = 0; j < nc; j ++) {
      rc += consonants[j/5];
    }
    for (int j = 0; j < nv-1; j ++) {
      for (int k = j+1; k < nv; k ++) {
        if (rv[j] > rv[k]) {
          char tmp = rv[j];
          rv[j] = rv[k];
          rv[k] = tmp;
        }
      }
    }
    for (int j = 0; j < nc-1; j ++) {
      for (int k = j+1; k < nc; k ++) {
        if (rc[j] > rc[k]) {
          char tmp = rc[j];
          rc[j] = rc[k];
          rc[k] = tmp;
        }
      }
    }
    for (int j = 0; j < nc; j ++) {
      result += rv[j];
      result += rc[j];
    }
    if (nv > nc) {
      result += rv[nv-1];
    }
    cout << "Case " << i+1 << ": " << result << '\n';
  }
  return 0;
}
