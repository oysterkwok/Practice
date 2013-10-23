#include <iostream>
#include <set>

using namespace std;

int main() {
  int n, m;
  cin >> n;
  for (int i = 0; i < n; i ++) {
    set<int> nums;
    cin >> m;
    int now = m;
    bool done = false;
    while (now != 1 && nums.find(now) == nums.end()) {
      nums.insert(now);
      int k = 0;
      while (now > 0) {
        k += (now % 10) * (now % 10);
        now /= 10;
      }
      now = k;
    }
    if (now == 1) {
      cout << "Case #" << i+1 << ": " << m << " is a Happy number.\n";
    }
    else {
      cout << "Case #" << i+1 << ": " << m << " is an Unhappy number.\n";
    }
  }
  return 0;
}
