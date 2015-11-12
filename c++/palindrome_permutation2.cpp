#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

void print_r(vector<string>& r) {
  for (int i = 0; i != r.size(); i++)  cout << r[i] << ",";
  cout << endl;
}


class Solution {
public:
    void helper(string s, vector<string>& res, int start) {
        if (start == s.size()) {
            res.push_back(s);
            return;
        }
        for(int i = start; i < s.size(); i++) {
            if (i != start && s[i] == s[start]) continue;
            std::swap(s[i], s[start]);
            helper(s, res, start+1);
        }
    }
    vector<string> generatePalindromes(string s) {
        vector<string> res;
        unordered_map<char, int> m;
        int odd = 0;
        for (int i = 0; i < s.size(); i++) {
            m[s[i]]++;
            if (m[s[i]] % 2 == 0) odd--;
            else odd++;
        }
        if (odd > 1) return res;
        string half;
        char odd_char;
        for (auto it : m) {
            half += string(it.second/2, it.first);
            if (it.second%2!=0) odd_char = it.first;
        }
        helper(half, res, 0);
        for (int i = 0; i < res.size(); i++) {
            string tmp = res[i];
            std::reverse(res[i].begin(), res[i].end());
            res[i] = tmp+(odd?string(1,odd_char):"")+res[i];
        }
        return res;
    }
};


int main() {
  Solution s;
  
  string t;
  vector<string> r;

  t = "aabcc";
  r = s.generatePalindromes(t);

  print_r(r);

  return 0;
}
