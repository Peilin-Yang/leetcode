#include<vector>
#include<unordered_map>
#include<iostream>
#include<ctime>

using namespace std;

class Solution {
private:
    unordered_map<int, int> m1;
    unordered_map<int, int> m2;
    vector<int> l;
public:
    void p() {
        cout << "Current MAP: ";
        for (auto it : m1) cout << it.first << ":" << it.second << ",";
        cout << endl;
    }
    void set(int key, int value) {
        if (m1.find(key) == m1.end()) {
            m2[key] = l.size();
            l.push_back(key);
        }
        m1[key] = value;
    }
    int get(int key) {
        if (m1.find(key) == m1.end()) return -1;
        return m1[key];
    }
    void del(int key) {
        m1.erase(key);
        int idx = m2[key];
        m2.erase(key);
        m2[l[l.size()-1]] = idx;
        swap(l[idx], l[l.size()-1]);
        l.erase(l.end()-1);
    }
    int get_random() {
        srand(time(NULL));
        int len = l.size();
        int idx = rand()%len;
        cout << "get random:" << l.size() << "--" << idx << "--" << l[idx] <<endl;
        return m1[l[idx]];
    }
};

int main() {
  Solution s;

  s.set(1, 5);
  s.set(1, 6);
  cout << s.get_random() << endl;
  cout << s.get(1) << endl;
  s.set(2, 3);
  cout << s.get_random() << endl;
  s.set(4, 10);
  cout << s.get_random() << endl;
  cout << s.get_random() << endl;
  cout << s.get_random() << endl;
  s.del(1);
  s.del(4);
  cout << s.get_random() << endl;
  cout << s.get_random() << endl;
  cout << s.get(1) << endl;
  return 0;
}
