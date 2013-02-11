#include <iostream>
#include <set>
#include <vector>
#include <cstring>

using namespace std;

int main() {
  set<string> stopwords;
  vector<vector<string> > context;
  set<string> words;
  string str;
  getline(cin, str);
  while (strcmp(str.c_str(), "::") != 0) {
    stopwords.insert(str);
    getline(cin, str);
  }
  while (getline(cin, str)) {
    str += ' ';
    vector<string> sentense;
    string buffer;
    for (int i = 0; i < str.length(); i ++) {
      if (str[i] >= 'A' && str[i] <= 'Z') {
        buffer += str[i] - 'A' + 'a';
      }
      else if (str[i] >= 'a' && str[i] <= 'z') {
        buffer += str[i];
      }
      else if (buffer.size() > 0) {
        sentense.push_back(buffer);
        if (stopwords.find(buffer) == stopwords.end()) {
          words.insert(buffer);
        }
        buffer.clear();
      }
    }
    context.push_back(sentense);
  }
  for (set<string>::iterator iter = words.begin(); iter != words.end(); iter ++) {
    for (int i = 0; i < context.size(); i ++) {
      for (int j = 0; j < context[i].size(); j ++) {
        if (strcmp(iter->c_str(), context[i][j].c_str()) == 0) {
          for (int k = 0; k < j; k ++) {
            cout << context[i][k] << ' ';
          }
          for (int k = 0; k < context[i][j].size(); k ++) {
            cout << (char) (context[i][j][k] - 'a' + 'A');
          }
          for (int k = j+1; k < context[i].size(); k ++) {
            cout << ' ' << context[i][k];
          }
          cout << '\n';
        }
      }
    }
  }
  return 0;
}
