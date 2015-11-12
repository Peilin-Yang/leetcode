#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
      int l = s.size();
      if (l == 0 || l == 1) return s;
      int start = 0, max_len = 1;
      for (int i = 0; i != l;) {
        if (l-i < max_len/2) break;
        int j = i, k = i;
        while (k < l-1 && s[k+1] == s[k]) { 
          k++;
        }
        i = k+1;
        while (k < l-1 && j > 0 && s[k+1] == s[j-1]) {
          k++;
          j--;
        }
        int cur_len = k-j+1;
        if (cur_len > max_len) {
          start = j;
          max_len = cur_len;
        }
      }
      cout << "start:" << start << "  max_len:" << max_len << endl;
      return s.substr(start, max_len);
    }
};


int main() {
    Solution *s = new Solution();
    string test;
    string r;

    test = "abacdfgdcaba";
    r = s->longestPalindrome(test);
    cout << test << " -> " << r << endl;

    test = "abb";
    r = s->longestPalindrome(test);
    cout << test << " -> " << r << endl;
    
    test = "bb";
    r = s->longestPalindrome(test);
    cout << test << " -> " << r << endl;
    
    test = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabcaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    r = s->longestPalindrome(test);
    cout << test << " -> " << r << endl;
    return 0;
}
