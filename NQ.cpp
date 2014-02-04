#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    void nqueen(int m, int n) {
        if (m >= n) {
            total ++;
            return;
        }
        else {
            for (int i = 0; i < n; i ++) {
                grid[m] = 1 << i;
                bool flag = true;
                for (int j = 0; j < m; j ++) {
                    flag &= ! (grid[j] & grid[m]);
                    flag &= ! ((grid[j] << (m-j)) & grid[m]);
                    flag &= ! ((grid[j] >> (m-j)) & grid[m]);
                    if (!flag) {
                        break;
                    }
                }
                if (flag) {
                    nqueen(m+1, n);
                }
            }
        }
    }
public:
    int totalNQueens(int n) {
        total = 0;
        grid.resize(n, 0);
        for (int i = 0; i < n; i ++) {
            grid[0] = 1 << i;
            nqueen(1, n);
        }
        return total;
    }

protected:
    int total;
    vector<int> grid;
};

int main() {
  int p;
  cin >> p;
  Solution ss;
  int q = ss.totalNQueens(p);
  cout << q << '\n';
}
