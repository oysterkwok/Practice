#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > tree;
vector<int> inord, postord;

void build_tree(int nid, int parent, vector<int> ins, vector<int> posts) {
  if (ins.size() == 0 || posts.size() == 0) {
    return;
  }
  int root = posts[posts.size()-1];
  vector<int> lins, lposts, rins, rposts;
  int index = 0;
  while (ins[index] != root) {
    lins.push_back(ins[index]);
    lposts.push_back(posts[index]);
    index ++;
  }
  while (index < ins.size()-1) {
    rins.push_back(ins[index+1]);
    rposts.push_back(posts[index]);
    index ++;
  }
  tree[nid].resize(5, 0);
  tree[nid][0] = root;
  if (lposts.size() > 0) {
    int lc = lposts[lposts.size()-1];
    tree[nid][1] = lc;
    tree[nid][4] = 1;
    build_tree(lc, root, lins, lposts);
  }
  if (rposts.size() > 0) {
    int rc = rposts[rposts.size()-1];
    tree[nid][2] = rc;
    tree[nid][4] = 1;
    build_tree(rc, root, rins, rposts);
  }
  tree[nid][3] = parent;
}

vector<int> readstr(string str) {
  vector<int> result;
  str += ' ';
  int buf = 0;
  for (int i = 0; i < str.size(); i ++) {
    if (str[i] == ' ') {
      result.push_back(buf);
      buf = 0;
    }
    else {
      buf = buf * 10 + str[i] - '0';
    }
  }
  return result;
}

int main() {
  int n;
  string str;
  while (getline(cin, str) != NULL) {
    inord = readstr(str);
    getline(cin, str);
    postord = readstr(str);
    n = inord.size();

    tree.clear();
    tree.resize(10000);
    
    build_tree(postord[n-1], 0, inord, postord);
    int min = 99999999, minx = 9999;
    for (int i = 0; i < n; i ++) {
      if (tree[inord[i]][4] == 0) {
        int current = 0;
        int k = inord[i];
        while (tree[k][3] > 0) {
          current += tree[k][0];
          k = tree[k][3];
        }
        if (current < min) {
          min = current;
          minx = inord[i];
        }
        if (current == min && inord[i] < minx) {
          minx = inord[i];
        }
      }
    }

    cout << minx << '\n';
  }
  return 0;
}
