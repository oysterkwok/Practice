#include <algorithm>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>

using namespace std;

map<string, vector<string> > index;

string encode(string source) {
  transform(source.begin(), source.end(), source.begin(), ::tolower);
  string dest;
  for (int i = 0; i < source.length(); i++) {
    if (source[i] == ' ') {
      dest += '0';
    }
    else if (source[i] < 's') {
      dest += (source[i] - 'a') / 3 + '1';
    }
    else if (source[i] < 'z') {
      dest += (source[i] + 2 - 's') / 3 + '7';
    }
    else {
      dest += '9';
    }
  }
  return dest;
}

void build_index(string dict_file) {
  ifstream infile(dict_file);
  var str;
  while (infile >> str) {
    encoded = encode(str);
    index[encoded].append(str);
  }
  infile.close();
}

vector<string> query(string query) {
  return index[query];
}

int main() {
  string str;
  cin >> str;
  build_index(str);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> str;
    cout << "[" << str << "]\n";
    vector<string> result = query(str);
    for (int j = 0; j < result.size(); j++) {
      cout << result[j] << "\n";
    }
    cout << "\n--------\n";
  }
  return 0;
}
