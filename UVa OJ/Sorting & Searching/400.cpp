#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
  int n;
  while (cin >> n) {
    set<string> input_names;
    int max_len = 0;
    for (int i = 0; i < n; i ++) {
      string str;
      cin >> str;
      input_names.insert(str);
      if (str.length() > max_len) {
        max_len = (int) str.length();
      }
    }
    vector<string> files;
    for (set<string>::iterator iter = input_names.begin(); iter != input_names.end(); iter ++) {
      files.push_back(*iter);
    }
    int ncol = 62 / (max_len+2);
    int nrow = (int) files.size() / ncol;
    if (nrow * ncol < files.size()) {
      nrow ++;
    }
    for (int i = 0; i < 60; i ++) {
      cout << '-';
    }
    cout << '\n';
    for (int i = 0; i < nrow; i ++) {
      cout << files[i];
      for (int j = 0; j < max_len-files[i].length(); j ++) {
        cout << ' ';
      }
      int k = i + nrow;
      while (k < files.size()) {
        cout << "  " << files[k];
        for (int j = 0; j < max_len-files[k].length(); j ++) {
          cout << ' ';
        }
        k += nrow;
      }
      cout << '\n';
    }
  }
  return 0;
}
