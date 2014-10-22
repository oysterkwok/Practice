#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool wordBreak(string s, set<string> &dict) {
  // letz try dfs
  if (s.length() == 0) {
    return true;
  }
  for (set<string>::iterator wi = dict.begin(); wi != dict.end(); wi ++) {
    string w = *wi;
    if (strcmp(s.substr(0, w.length()).c_str(), w.c_str()) == 0) {
      if (wordBreak(s.substr(w.length()), dict)) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  string str;
  string word;
  cin >> word;
  set<string> dict;
  while (cin >> str) {
    dict.insert(str);
  }
  cout << wordBreak(word, dict) << '\n';
}
