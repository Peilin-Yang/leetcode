#include<unordered_map>
#include<list>
#include<algorithm>
#include <stdexcept>
#include <iostream>

using namespace std;

class LRUCache{
private:
    std::unordered_map<int, list<pair<int,int> >::iterator > mapping;
    std::list<pair<int, int> > value_list;
    int _capacity;
public:
    LRUCache(int capacity) {
      _capacity = capacity;   
    }
    
    void makefront(list<pair<int,int> >::iterator &it) {
      if (it != value_list.begin()) {
        value_list.splice(value_list.begin(), value_list, it);
      }
    }
    
    int get(int key) {
      int r;
      auto it = mapping.find(key);
      if (it == mapping.end()) return -1;
      makefront(it->second);
      r = value_list.front().second;
      return r;
    }
    
    void set(int key, int value) {
      if (mapping.find(key) != mapping.end()) {
        *mapping[key] = std::make_pair(key, value);
        makefront(mapping[key]);
      } else {
        if (mapping.size() >= _capacity) {
          mapping.erase(value_list.rbegin()->first);
          *value_list.rbegin() = std::make_pair(key, value);
          makefront(--value_list.end());
        } else {
          value_list.emplace(value_list.begin(), key, value);
        }
        mapping[key] = value_list.begin();
      }
    }

    void print_list() {
      cout << "---------" << endl;
      for (std::list<pair<int,int> >::iterator it=value_list.begin(); it!=value_list.end(); it++) {
        cout << it->first << ":" << it->second;
      }
      cout << endl;
      cout << "---------" << endl;
    }
};


int main() {
  LRUCache l(1);  
  l.set(2,1);
  l.print_list();
  cout << l.get(2) << endl;
  l.set(3,2);
  l.print_list();
  cout << l.get(2) << endl;
  cout << l.get(3) << endl;

  return 0;
}
