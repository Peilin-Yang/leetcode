#include<cstdlib>
#include<iostream>
#include<sstream>
#include<unordered_map>

using namespace std;
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> m1;
        unordered_map<string, char> m2;
        if (pattern.empty() || str.empty()) return false;
        istringstream is(str);
        string s;
        int i = 0;
        for (; i < pattern.size(); i++) {
            is >> s;
            cout << "s::: " << s << endl;
            if (s.empty()) return false;
            char c = pattern[i];
            if (m1.find(c) == m1.end()) m1[c] = s;
            else if (m1[c] != s) return false;
            if (m2.find(s) == m2.end()) m2[s] = c;
            else if (m2[s] != c) return false;
        }
        cout << i << endl;
        //is >> s;
        //cout << "s:" << s << " " << s.empty() << endl;
        return is>>s;
    }
};

int main() {
  Solution s;
  string str1,str2;
  
  str1 = "abba";
  str2 = "dog cat cat dog";
  cout << s.wordPattern(str1, str2) << endl;

  return 0;
}
