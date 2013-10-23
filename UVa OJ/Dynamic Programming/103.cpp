#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int> > counts;
vector<vector<int> > boxes;

bool boxcmp(int x, int y) {
  for (int i = 0; i < m; i ++) {
    if (boxes[x][i] >= boxes[y][i]) {
      return false;
    }
  }
  return true;
}

int dp(int x) {
  if (counts[x].size() > 0) {
    return counts[x][0];
  }
  int max = 0, maxi = -1;
  for (int i = 0; i < n; i ++) {
    if (boxcmp(x, i)) {
      int now = dp(i);
      if (now > max) {
        max = now;
        maxi = i;
      }
    }
  }
  
  counts[x].push_back(1+max);
  counts[x].push_back(x);
  if (maxi >= 0) {
    for (int i = 1; i < counts[maxi].size(); i ++) {
      counts[x].push_back(counts[maxi][i]);
    }
  }
  return counts[x][0];
}

int main() {
  cin >> n;
  while (!cin.fail()) {
    cin >> m;
    boxes.resize(n);
    for (int i = 0; i < n; i ++) {
      boxes[i].resize(m);
      for (int j = 0; j < m; j ++) {
        cin >> boxes[i][j];
      }
      for (int j = 0; j < m-1; j ++) {
        for (int k = j+1; k < m; k ++) {
          if (boxes[i][j] < boxes[i][k]) {
            int temp = boxes[i][j];
            boxes[i][j] = boxes[i][k];
            boxes[i][k] = temp;
          }
        }
      }
    }

    counts.resize(n);
    for (int i = 0; i < n; i ++) {
      counts[i].clear();
    }

    int max = 0, maxi = 0;
    for (int i = 0; i < n; i ++) {
      int now = dp(i);
      if (now > max) {
        max = now;
        maxi = i;
      }
    }
    cout << max << '\n';
    cout << counts[maxi][1]+1;
    for (int i = 2; i < counts[maxi].size(); i ++) {
      cout << " " << counts[maxi][i]+1;
    }
    cout << '\n';
    cin >> n;
  }
  return 0;
}
