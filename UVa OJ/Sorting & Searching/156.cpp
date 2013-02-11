#include <iostream>
#include <set>
#include <vector>
#include <cstring>

using namespace std;

int main() {
  string line;
  vector<string> dict;
  vector<string> dict_key;
  getline(cin, line);
  while (strcmp(line.c_str(), "#") != 0) {
    line += ' ';
    string obuf, ucbuf;
    for (int i = 0; i < line.length(); i ++) {
      if (line[i] >= 'A' && line[i] <= 'Z') {
        obuf += line[i];
        ucbuf += line[i];
      }
      else if (line[i] >= 'a' && line[i] <= 'z') {
        obuf += line[i];
        ucbuf += line[i] - 'a' + 'A';
      }
      else {
        if (obuf.size() > 0) {
          dict.push_back(obuf);
          for (int j = 0; j < ucbuf.size()-1; j ++) {
            for (int k = j+1; k < ucbuf.size(); k ++) {
              if (ucbuf[j] > ucbuf[k]) {
                ucbuf[j] += ucbuf[k];
                ucbuf[k] = ucbuf[j] - ucbuf[k];
                ucbuf[j] -= ucbuf[k];
              }
            }
          }
          dict_key.push_back(ucbuf);
          obuf.clear();
          ucbuf.clear();
        }
      }
    }
    getline(cin, line);
  }
  set<string> result;
  for (int i = 0; i < dict.size(); i ++) {
    bool found = false;
    for (int j = 0; j < dict.size(); j ++) {
      if (i != j && strcmp(dict_key[i].c_str(), dict_key[j].c_str()) == 0) {
        found = true;
        break;
      }
    }
    if (!found) {
      result.insert(dict[i]);
    }
  }
  for (set<string>::iterator iter = result.begin(); iter != result.end(); iter ++) {
    cout << *iter << '\n';
  }
  return 0;
}
