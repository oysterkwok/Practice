#include <iostream>
#include <vector>

using namespace std;

int minimumTotal(vector<vector<int> > &triangle) {
        if (triangle.size() == 0) {
            return 0;
        }
        int n = triangle.size();
        vector<int> cache = triangle[n-1];
        for (int i = n-2; i >= 0; i --) {
            vector<int> next;
            for (int j = 0; j <= i; j ++) {
                int d = triangle[i][j] + (cache[j]<cache[j+1])?cache[j]:cache[j+1];
cout << "d: " << d << '\n';
next.push_back(d);
            }
            cache = next;
        }
        return cache[0];
    }

int main() {
  vector<vector<int> > triangle;
  triangle.resize(2);
  triangle[0].push_back(-1);
  triangle[1].push_back(-2);
  triangle[1].push_back(-3);
  cout << minimumTotal(triangle);
}
