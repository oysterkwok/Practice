#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  string str;
  getline(cin, str);
  vector<vector<int> > history;
  while (getline(cin, str)!=NULL) {
    vector<int> list;
    str += ' ';
    int buf = 0;
    for (int i = 0; i < str.size(); i ++) {
      if (str[i] == ' ' && buf > 0) {
        list.push_back(buf);
        buf = 0;
      }
      if (str[i] != ' ') {
        buf = buf * 10 + str[i] - '0';
      }
    }
    history.push_back(list);
  }

  for (int i = 1; i < history.size(); i ++) {
    vector<int> re;
    re.resize(n);
    for (int j = 0; j < n; j ++) {
      re[history[0][j]-1] = history[i][j];
    }
    vector<int> count;
    count.resize(n, 1);
    for (int j = n-2; j >= 0; j --) {
      for (int k = j+1; k < n; k ++) {
        if (re[j] < re[k] && count[j] < count[k]+1) {
          count[j] = count[k] + 1;
        }
      }
    }
    int max = 0;
    for (int j = 1; j < n; j ++) {
      if (count[max] < count[j]) {
        max = j;
      }
    }
    cout << count[max] << '\n';
  }
  return 0;
}
