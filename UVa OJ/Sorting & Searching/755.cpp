#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  map<char, char> c2d;
  c2d['A'] = '2';
  c2d['B'] = '2';
  c2d['C'] = '2';
  c2d['D'] = '3';
  c2d['E'] = '3';
  c2d['F'] = '3';
  c2d['G'] = '4';
  c2d['H'] = '4';
  c2d['I'] = '4';
  c2d['J'] = '5';
  c2d['K'] = '5';
  c2d['L'] = '5';
  c2d['M'] = '6';
  c2d['N'] = '6';
  c2d['O'] = '6';
  c2d['P'] = '7';
  c2d['R'] = '7';
  c2d['S'] = '7';
  c2d['T'] = '8';
  c2d['U'] = '8';
  c2d['V'] = '8';
  c2d['W'] = '9';
  c2d['X'] = '9';
  c2d['Y'] = '9';

  int nc;
  cin >> nc;
  for (int i = 0; i < nc; i ++) {
    if (i > 0) {
      cout << '\n';
    }
    map<string, int> num_book;
    num_book.clear();
    int n;
    cin >> n;
    for (int j = 0; j < n; j ++) {
      string num;
      cin >> num;
      string cleaned;
      for (int k = 0; k < num.length(); k ++) {
        if (num[k] == '-') {
          continue;
        }
        if (num[k] >= 'A' && num[k] <= 'Z') {
          cleaned += c2d[num[k]];
        }
        else if (num[k] >= '0' && num[k] <= '9') {
          cleaned += num[k];
        }
      }
      if (num_book.find(cleaned) == num_book.end()) {
        num_book[cleaned] = 1;
      }
      else {
        num_book[cleaned] ++;
      }
    }
    bool no_dupl = true;
    for (map<string, int>::iterator iter = num_book.begin(); iter != num_book.end(); iter ++) {
      if (iter->second > 1) {
        no_dupl = false;
        for (int j = 0; j < 3; j ++) {
          cout << iter->first[j];
        }
        cout << '-';
        for (int j = 3; j < 7; j ++) {
          cout << iter->first[j];
        }
        cout << ' ' << iter->second << '\n';
      }
    }
    if (no_dupl) {
      cout << "No duplicates.\n";
    }
  }
  return 0;
}
