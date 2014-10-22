#include <iostream>
#include <set>

using namespace std;

int main() {
  set<string> dict;
  string str;
  while ((cin >> str) != NULL) {
    dict.insert(str);
  }
  for (set<string>::iterator iter = dict.begin(); iter != dict.end(); iter ++) {
    str = *iter;
    for (int i = 1; i < str.length()-1; i ++) {
      string str1 = str.substr(0, i);
      string str2 = str.substr(i);
      if (dict.find(str1) != dict.end() && dict.find(str2) != dict.end()) {
        cout << str << '\n';
      }
    }
  }
}
