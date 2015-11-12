#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void print_v(vector<string>& v) {
  for (int i = 0; i != v.size(); i++) cout << v[i] << ",";
  cout << endl;
}

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        if (s.size() < 10) return res;
        unordered_map<string, int> m;
        for (int i = 0; i < s.size()-9; i++) {
            m[s.substr(i, 10)]++;
        }
        for (auto x : m) {
            if (x.second > 1) res.push_back(x.first);
        }
        return res;
    }
};

int main() {
  Solution s;
  
  //string t = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
  //string t = "";
  string t = "AAAAAAAAAAA";
  vector<string> r = s.findRepeatedDnaSequences(t);
  print_v(r);

  return 0;
}
