#include <iostream>
#include <vector>

using namespace std;

int main() {
  int x, y, z;
  cin >> x >> y >> z;
  vector<vector<int> > trees;
  while (x > 0 || y > 0 || z > 0) {
    vector<int> tree;
    tree.push_back(x);
    tree.push_back(y);
    tree.push_back(z);
    trees.push_back(tree);
    cin >> x >> y >> z;
  }
  vector<int> histogram;
  histogram.resize(10, 0);
  for (int i = 0; i < trees.size(); i ++) {
    int mindist = 101;
    for (int j = 0; j < trees.size(); j ++) {
      if (i == j) {
        continue;
      }
      int dist = 0;
      for (int k = 0; k < 3; k ++) {
        dist += (trees[i][k] - trees[j][k]) * (trees[i][k] - trees[j][k]);
      }
      if (dist < mindist) {
        mindist = dist;
      }
    }
    for (int j = 1; j < 11; j ++) {
      if (mindist < j*j) {
        histogram[j-1] ++;
        break;
      }
    }
  }
  for (int i = 0; i < 10; i ++) {
    if (histogram[i] >= 0 && histogram[i] < 10) {
      cout << "   " << histogram[i];
    }
    else if (histogram[i] >= 10 && histogram[i] < 100) {
      cout << "  " << histogram[i];
    }
    else if (histogram[i] >= 100 && histogram[i] < 1000) {
      cout << " " << histogram[i];
    }
    else {
      cout << histogram[i];
    }
  }
  cout << '\n';
  return 0;
}
