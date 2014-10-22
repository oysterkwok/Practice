#include <iostream>
#include <map>
#include <vector>

using namespace std;

class LRUCache{
protected:
  map<int, int> vtable;
  map<int, int> rtable;
  vector<int> ranks;
  int capa;

public:
    LRUCache(int capacity) {
        vtable.clear();
        rtable.clear();
        ranks.resize(capacity);
        capa = capacity;
    }
    
    int get(int key) {
        if (vtable.find(key) == vtable.end()) {
            return -1;
        }
        else {
            int rlast = rtable[key];
            for (int i = rlast; i > 0; i --) {
                rtable[ranks[i-1]] ++;
                ranks[i] = ranks[i-1];
            }
            ranks[0] = key;
            rtable[key] = 0;
            return vtable[key];
        }
    }
    
    void set(int key, int value) {
        int val = get(key);
        if (val == -1) {
            vtable.erase(ranks[capa-1]);
            rtable.erase(ranks[capa-1]);
            for (int i = capa-1; i > 0; i --) {
                rtable[ranks[i-1]] ++;
                ranks[i] = ranks[i-1];
            }
            ranks[0] = key;
            rtable[key] = 0;
            vtable[key] = value;
        }
        else {
            vtable[key] = value;
        }
    }
};

int main() {
  LRUCache *lru = new LRUCache(3);
  cout << lru->get(700) << '\n';
  lru->set(500, 1);
  cout << lru->get(500) << '\n';
  cout << lru->get(700) << '\n';
  lru->set(6, 2);
  lru->set(700, 3);
  cout << lru->get(500) << '\n';
  lru->set(700, 5);
  cout << lru->get(700) << '\n';
  cout << lru->get(6) << '\n';
  for (int i = 0; i < 10; i ++) {
    lru->set(i, i);
  }
  lru->set(1, 11);
  lru->set(2, 22);
  for (int i = 0; i < 10; i ++) {
    cout << lru->get(i) << ':' << i << '\n';
  }
}
