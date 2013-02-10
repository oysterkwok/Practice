#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
  srand(time(NULL));

  int n = 50000;
  cout << n << ' ' << n << '\n';

  long long first = 999999999999;
  for (int i = 0; i < n; i ++) {
    long long current = first / (i+1) + rand() % 1000 - 500;
    if (current < 0) {
      current = 0;
    }
    cout << current << ' ' << i+1 << '\n';
  }
}
