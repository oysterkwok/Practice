#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
  int n;
  cin >> n;
  string tmp;
  getline(cin, tmp);
  map<string, int> counts;
  for (int i = 0; i < n; i ++) {
    string line;
    getline(cin, line);
    int head = 0;
    while (head < line.length() && line[head] != ' ') {
      head ++;
    }
    string country = line.substr(0, head);
    if (counts.find(country) == counts.end()) {
      counts[country] = 1;
    }
    else {
      counts[country] ++;
    }
  }
  for (map<string, int>::iterator iter = counts.begin(); iter != counts.end(); iter ++) {
    cout << iter->first << ' ' << iter->second << '\n';
  }
  return 0;
}
