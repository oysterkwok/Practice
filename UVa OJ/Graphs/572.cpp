#include <iostream>
#include <vector>

using namespace std;

vector<string> grid;
int n, m, k;

void passing(int x, int y) {
  grid[x][y] = '*';
  if (x>0 && grid[x-1][y] == '@') passing(x-1, y);
  if (x<n-1 && grid[x+1][y] == '@') passing(x+1, y);
  if (y>0 && grid[x][y-1] == '@') passing(x, y-1);
  if (y<m-1 && grid[x][y+1] == '@') passing(x, y+1);

  if (x>0 && y>0 && grid[x-1][y-1] == '@') passing(x-1, y-1);
  if (x>0 && y<m-1 && grid[x-1][y+1] == '@') passing(x-1, y+1);
  if (x<n-1 && y>0 && grid[x+1][y-1] == '@') passing(x+1, y-1);
  if (x<n-1 && y<m-1 && grid[x+1][y+1] == '@') passing(x+1, y+1);

}

int main() {
  cin >> n >> m;
  while (n > 0 && m > 0) {
    grid.clear();
    k = 0;
    for (int i = 0; i < n; i ++) {
      string str;
      cin >> str;
      grid.push_back(str);
    }
    for (int i = 0; i < n; i ++) {
      for (int j = 0; j < m; j ++) {
        if (grid[i][j] == '@') {
          k ++;
          passing(i, j);
        }
      }
    }
    cout << k << '\n';
    cin >> n >> m;
  }
  return 0;
}
