#include <iostream>
#include <vector>

using namespace std;

int main() {
  string line;
  while (getline(cin, line)) {
    vector<int> cakes;
    int head = 0;
    int di = 0;
    while (head < line.length()) {
      if (line[head] >= '0' && line[head] <= '9') {
        di = di * 10 + line[head] - '0';
      }
      else {
        cakes.push_back(di);
        di = 0;
      }
      head ++;
    }
    if (di > 0) {
      cakes.push_back(di);
    }

    vector<int> result;
    for (int i = 0; i < cakes.size()-1; i ++) {
      int maxj = cakes.size()-i-1;
      for (int j = 0; j < cakes.size()-i-1; j ++) {
        if (cakes[j] > cakes[maxj]) {
          maxj = j;
        }
      }
      if (maxj < cakes.size()-i-1) {
        if (maxj > 0) {
          result.push_back(cakes.size()-maxj);
          for (int j = 0; j < (maxj+1)/2; j ++) {
            cakes[j] += cakes[maxj-j];
            cakes[maxj-j] = cakes[j] - cakes[maxj-j];
            cakes[j] -= cakes[maxj-j];
          }
        }
        result.push_back(i+1);
        for (int j = 0; j < (cakes.size()-i)/2; j ++) {
          cakes[j] += cakes[cakes.size()-i-1-j];
          cakes[cakes.size()-i-1-j] = cakes[j] - cakes[cakes.size()-i-1-j];
          cakes[j] -= cakes[cakes.size()-i-1-j];
        }
      }
    }
    cout << line << '\n';
    for (int i = 0; i < result.size(); i ++) {
      cout << result[i] << ' ';
    }
    cout << "0\n";
  }
  return 0;
}
