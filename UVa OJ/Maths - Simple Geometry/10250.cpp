#include<iostream>

using namespace std;

int main() {
  double x1, y1, x2, y2;
  while (cin >> x1) {
    cin >> y1 >> x2 >> y2;
    double cx = (x1+x2) / 2;
    double cy = (y1+y2) / 2;
    if (x1 == x2 && y1 == y2) {
      cout << "Impossible.\n";
    }
    else {
      double x3 = cx + y1 - cy;
      double y3 = cy - x1 + cx;
      double x4 = cx - y1 + cy;
      double y4 = cy + x1 - cx;
      cout.precision(10);
      cout << fixed << x3 << ' ' << y3 << ' ' << x4 << ' ' << y4 << '\n';
    }
  }
}
