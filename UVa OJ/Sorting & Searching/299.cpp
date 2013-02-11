#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i ++) {
    int m;
    cin >> m;
    vector<int> train;
    for (int j = 0; j < m; j ++) {
      int k;
      cin >> k;
      train.push_back(k);
    }
    int nswap = 0;
    for (int j = 0; j < m; j ++) {
      for (int k = 0; k < m-1; k ++) {
        if (train[k] > train[k+1]) {
          nswap ++;
          train[k+1] += train[k];
          train[k] = train[k+1] - train[k];
          train[k+1] -= train[k];
        }
      }
    }
    cout << "Optimal train swapping takes " << nswap << " swaps.\n";
  }
  return 0;
}
