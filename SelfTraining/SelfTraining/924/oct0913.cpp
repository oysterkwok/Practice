#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

map<string, vector<int> > inverted_index;

void min_full_sub(vector<string> doc, set<string> dict, int & start, int & end) {
  // build inv_ind, O(n_doc)
  inverted_index.clear();
  for (int i = 0; i < doc.size(); i ++) {
    if (dict.find(doc[i]) != dict.end()) {
      vector<int> list = inverted_index.find(doc[i])->second;
      list.push_back(i);
      inverted_index[doc[i]] = list;
    }
  }
  
  // init items
  // TODO using max_heap and min_heap instead of array to reduce the runtime from O(n_doc * n_dict) to O(n_doc * log(n_dict))
  vector<int> idxes;
  for (map<string, vector<int> >::iterator iter = inverted_index.begin(); iter != inverted_index.end(); iter ++) {
    idxes.push_back(iter->second[0]);
  }
  start = 0;
  end = doc.size();
  
  // find until finish
  while (1) {
    int min_i = 0, max_i = 0;  // the index of index
    for (int i = 1; i < idxes.size(); i ++) {
      if (idxes[min_i] > idxes[i]) {
        min_i = i;
      }
      if (idxes[max_i] < idxes[i]) {
        max_i = i;
      }
    }
    if (end - start > idxes[max_i] - idxes[min_i]) {
      start = idxes[min_i];
      end = idxes[max_i];
    }
    vector<int> list = inverted_index.find(doc[idxes[min_i]])->second;
    if (list.size() <= 1) {
      break;
    }
    int next = list[1];
    list.erase(list.begin());
    inverted_index[doc[idxes[min_i]]] = list;
    idxes[min_i] = next;
  }
}

int main() {
  vector<string> doc;
  set<string> dict;
  string str;
  cin >> str;
  while (strcmp(str.c_str(), "#")) {
    doc.push_back(str);
    cin >> str;
  }
  cin >> str;
  while (strcmp(str.c_str(), "#")) {
    dict.insert(str);
    cin >> str;
  }
  int start, end;
  min_full_sub(doc, dict, start, end);
  cout << "Start = " << start << "\nEnd = " << end << '\n';
  return 0;
}
