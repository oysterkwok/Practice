#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int evalRPN(vector<string> &tokens) {
  vector<int> stack;
  for (int i = 0; i < tokens.size(); i ++) {
    if (strcmp(tokens[i].c_str(), "+") == 0) {
      int y = stack[stack.size()-1];
      stack.pop_back();
      int x = stack[stack.size()-1];
      stack.pop_back();
      stack.push_back(x+y);
      continue;
    }
    if (strcmp(tokens[i].c_str(), "-") == 0) {
      int y = stack[stack.size()-1];
      stack.pop_back();
      int x = stack[stack.size()-1];
      stack.pop_back();
      stack.push_back(x-y);
      continue;
    }
    if (strcmp(tokens[i].c_str(), "*") == 0) {
      int y = stack[stack.size()-1];
      stack.pop_back();
      int x = stack[stack.size()-1];
      stack.pop_back();
      stack.push_back(x*y);
      continue;
    }
    if (strcmp(tokens[i].c_str(), "/") == 0) {
      int y = stack[stack.size()-1];
      stack.pop_back();
      int x = stack[stack.size()-1];
      stack.pop_back();
      stack.push_back(x/y);
      continue;
    }
    int num = atoi(tokens[i].c_str());
    stack.push_back(num);
  }
  return stack[0];
}

int main() {
  string str;
  vector<string> tokens;
  while (cin >> str) {
    if (strcmp(str.c_str(), "#") != 0) {
      tokens.push_back(str);
    }
    else {
      cout << evalRPN(tokens) << '\n';
      tokens.clear();
    }
  }
}
