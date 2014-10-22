#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int a, b, s, m, n;
  double pi = 3.1415926;
  cin >> a >> b >> s >> m >> n;
  while (s > 0) {
     int sum_a = a * m;
     int sum_b = b * n;
     cout.precision(2);
     cout << fixed;
     cout << atan(1.0 * sum_b / sum_a)*180.0/pi << ' ' << sqrt(1.0*sum_a*sum_a + sum_b*sum_b)/s << '\n';
     cin >> a >> b >> s >> m >> n;
  }
  return 0;
}
