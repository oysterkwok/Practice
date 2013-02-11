#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool rank(vector<int>, vector<int>);

bool rank(vector<int> best, vector<int> iter) {
  if (best[0] > iter[0]) {
    return false;
  }
  if (best[0] < iter[0]) {
    return true;
  }
  if (best[2] > iter[2]) {
    return false;
  }
  if (best[2] < iter[2]) {
    return true;
  }
  if (best[5] > iter[5]) {
    return false;
  }
  if (best[5] < iter[5]) {
    return true;
  }
  if (best[6] > iter[6]) {
    return false;
  }
  if (best[6] < iter[6]) {
    return true;
  }
  if (best[1] < iter[1]) {
    return false;
  }
  if (best[1] > iter[1]) {
    return true;
  }
  return false;
}

int main() {
  int n;
  cin >> n;
  string line;
  getline(cin, line);
  for (int i = 0; i < n; i ++) {
    map<string, vector<int> > stats;
    map<string, string> tn;
    getline(cin, line);
    if (i > 0) {
      cout << '\n';
    }
    cout << line << '\n';
    int nteam;
    cin >> nteam;
    getline(cin, line);
    for (int j = 0; j < nteam; j ++) {
      getline(cin, line);
      string lcteam;
      for (int k = 0; k < line.length(); k ++) {
        if (line[k] >= 'A' && line[k] <= 'Z') {
          lcteam += line[k] - 'A' + 'a';
        }
        else {
          lcteam += line[k];
        }
      }
      tn[lcteam] = line;
      vector<int> stat;
      stat.resize(8, 0);
      stats[lcteam] = stat;
    }
    int nmatch;
    cin >> nmatch;
    getline(cin, line);
    for (int j = 0; j < nmatch; j ++) {
      getline(cin, line);
      string t1, t2;
      int g1 = 0, g2 = 0;
      int head = 0;
      while (line[head] != '#') {
        if (line[head] >= 'A' && line[head] <= 'Z') {
          t1 += line[head] - 'A' + 'a';
        }
        else {
          t1 += line[head];
        }
        head ++;
      }
      head ++;
      while (line[head] != '@') {
        g1 = g1 * 10 + line[head] - '0';
        head ++;
      }
      head ++;
      while (line[head] != '#') {
        g2 = g2 * 10 + line[head] - '0';
        head ++;
      }
      head ++;
      while (head < line.length()) {
        if (line[head] >= 'A' && line[head] <= 'Z') {
          t2 += line[head] - 'A' + 'a';
        }
        else {
          t2 += line[head];
        }
        head ++;
      }
      stats[t1][1] ++;
      stats[t2][1] ++;
      if (g1 > g2) {
        stats[t1][0] += 3;
        stats[t1][2] ++;
        stats[t2][4] ++;
      }
      else if (g1 == g2) {
        stats[t1][0] ++;
        stats[t1][3] ++;
        stats[t2][0] ++;
        stats[t2][3] ++;
      }
      else {
        stats[t1][4] ++;
        stats[t2][0] += 3;
        stats[t2][2] ++;
      }
      stats[t1][5] += g1 - g2;
      stats[t1][6] += g1;
      stats[t1][7] += g2;
      stats[t2][5] += g2 - g1;
      stats[t2][6] += g2;
      stats[t2][7] += g1;
    }

    for (int j = 0; j < nteam; j ++) {
      map<string, vector<int> >::iterator best = stats.begin();
      for (map<string, vector<int> >::iterator iter = stats.begin(); iter != stats.end(); iter ++) {
        if (rank(best->second, iter->second)) {
          best = iter;
        }
      }
      cout << j+1 << ") " << tn[best->first] << ' ' << best->second[0] << "p, " << best->second[1] << "g (" << best->second[2] << '-' << best->second[3] << '-' << best->second[4] << "), " << best->second[5] << "gd (" << best->second[6] << '-' << best->second[7] << ")\n";
      best->second[0] = -1;
    } 
  }
  return 0;
}
