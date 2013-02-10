#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

vector<int> ri;
vector<long long> fi;
vector<string> si;

void qs(int, int);
bool compare(int, int);

void qs(int head, int tail) {
  if (head >= tail) {
    return;
  }
  int mid = (head + tail) / 2;
  int ph = head;
  int pt = tail;
  int cpr = ri[mid];
  ri[mid] = ri[pt];
  while (ph < pt) {
    if (compare(ri[ph], cpr)) {
      ph ++;
    }
    else {
      ri[pt] = ri[ph];
      pt --;
      ri[ph] = ri[pt];
    }
  }
  ri[ph] = cpr;
  qs(head, ph-1);
  qs(ph+1, tail);
}

bool compare(int xid, int yid) {
  long long xv, yv;
  xv = fi[xid] * (xid+1);
  yv = fi[yid] * (yid+1);
  if (xv > yv) {
    return true;
  }
  if (xv < yv) {
    return false;
  }
  if (xid > yid) {
    return false;
  }
  return true;
}

int main() {
  long m, n;
  cin >> n >> m;
  for (int i = 0; i < n; i ++) {
    long long f;
    string s;
    cin >> f >> s;
    ri.push_back(i);
    fi.push_back(f);
    si.push_back(s);
  }
  qs(0, n-1);
  for (int i = 0; i < m; i ++) {
    cout << si[ri[i]] << '\n';
  }
  return 0;
}
