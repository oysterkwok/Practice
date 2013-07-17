#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int blocks[26][26];
  int pos[25];
  for (int i = 0; i < n; i ++) {
    blocks[i][25] = 1;
    blocks[i][0] = i;
    pos[i] = i;
  }
  
  string str;
  cin >> str;
  while (strcmp(str.c_str(), "quit") != 0) {
    int x, y;
    string str2;
    cin >> x >> str2 >> y;
    
    int a1, a2, b1, b2;

    if (strcmp(str.c_str(), "move")==0 && strcmp(str2.c_str(), "onto")==0) {
      a1 = pos[x];
      b1 = pos[y];
      if (a1 != b1) {
        for (int i = 0; i < blocks[a1][25]; i ++) {
          if (blocks[a1][i] == x) {
            a2 = i;
            break;
          }
        }
        for (int i = a2; i < blocks[a1][25]; i ++) {
        }
      }
    }
    if (strcmp(str.c_str(), "move")==0 && strcmp(str2.c_str(), "over")==0) {
    }
    if (strcmp(str.c_str(), "pile")==0 && strcmp(str2.c_str(), "onto")==0) {
    }
    if (strcmp(str.c_str(), "pile")==0 && strcmp(str2.c_str(), "over")==0) {
    }
    cin >> str;
  }
  return 0;
}
