#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    string no_duplicate_adjcent_string(string s) {
        if (s.empty()) return s;
        int cur, last = 0;
        while (last < s.size()) {
            cur = last+1;
            if (s[cur] == s[last]) {
                last++;
                while (s[cur] == s[last]) cur++;
                swap(s[cur], s[last]);
            } else last++;
        }
        return s;
    }
};

int main() {
  Solution s;

  cout << s.no_duplicate_adjcent_string("aaabbcdc") << endl;
  return 0;
}
