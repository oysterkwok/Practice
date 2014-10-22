#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

map<string, vector<string> > cache;

vector<string> wordBreak(string s, set<string> &dict) {
  // letz try dfs
  if (cache.find(s) != cache.end()) {
    return cache.find(s)->second;
  }
  vector<string> result;
  for (set<string>::iterator wi = dict.begin(); wi != dict.end(); wi ++) {
    string w = *wi;
    if (strcmp(s.substr(0, w.length()).c_str(), w.c_str()) == 0) {
      if (s.length() == w.length()) {
        result.push_back(w);
      }
      else {
        vector<string> sub_result = wordBreak(s.substr(w.length()), dict);
        for (int i = 0; i < sub_result.size(); i ++) {
          result.push_back(w + " " + sub_result[i]);
        }
      }
    }
  }
  cache[s] = result;
  return result;
}

int main() {
  string str;
  string word;
  cin >> word;
  set<string> dict;
  while (cin >> str) {
    dict.insert(str);
  }
  vector<string> result = wordBreak(word, dict);
  for (int i = 0; i < result.size(); i ++) {
    cout << result[i] << '\n';
  }
}
