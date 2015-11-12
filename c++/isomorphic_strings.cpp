#include <vector>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
      int sl = s.size();
      int tl = t.size();
      if (sl != tl) return false;
      int m1[300] = {0};
      int m2[300] = {0};
      for (int i = 0; i != sl; i++) {
        if (m1[s[i]] != m2[t[i]]) {return false;}
        m1[s[i]] = i+1;
        m2[t[i]] = i+1;
      }
      return true;
    }
};


int main() {
  Solution s;

  string a1;
  string a2;
  a1 = "paper";
  a2 = "title";

  cout << std::boolalpha << s.isIsomorphic(a1, a2) << endl;

  return 0;
}
