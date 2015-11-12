#include<iostream>
#include<unordered_map>
#include<unordered_set>

using namespace std;
class Solution {
public:
    bool match(string pattern, int i, string str, int j, unordered_map<char, string>& m, unordered_set<string> s) {
        if (i == pattern.size() && j == str.size()) return true;
        if (i == pattern.size() || j == str.size()) return false;
        char c = pattern[i];
        if (m.find(c) != m.end()) {
            string t = m[c];
            if (str.find(t, j) != j) return false;
            return match(pattern, i+1, str, j+t.size(), m, s);
        }
        for (int k = j; k < str.size(); k++) {
            string t = str.substr(j, k-j+1);
            if (s.find(t) != s.end()) continue;
            m[c] = t;
            s.insert(t);
            if (match(pattern, i+1, str, k+1, m, s)) return true;
            m.erase(c);
            s.erase(t);
        }
        return false;
    }
    bool wordPatternMatch(string pattern, string str) {
        unordered_map<char, string> m;
        unordered_set<string> s;
        return match(pattern, 0, str, 0, m, s);
    }
};

int main() {
  Solution s;
  string str1,str2;
  
  str1 = "abba";
  str2 = "dogcatcatdog";
  cout << s.wordPatternMatch(str1, str2) << endl;

  return 0;
}
