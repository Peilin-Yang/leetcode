#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_len = 0, start = 0;
        int l = s.size();
        vector<int> idx(256, -1);
        for (int i = 0; i != l; i++) {
          //int c = s[i] - 'a';
          const unsigned char c=(unsigned char)s[i];
          int j = idx[c];
          idx[c] = i;
          //cout << "i:" << i << " s[i]:" << s[i] << " c:" << c << " j:" << j;
          if (start <= j) {
            start = j+1;
          }
          max_len = max(max_len, i-start+1);
          //cout << " start:" << start << " max_len:" << max_len << endl;
        }
        return max_len;
    }
};


int main()
{
    Solution *s = new Solution();
    int r;
    string t1("abcabcbb");
    r = s->lengthOfLongestSubstring(t1);
    cout << r << endl;
    string t2 = "bbbbbbbbb";
    r = s->lengthOfLongestSubstring(t2);
    cout << r << endl;
    string t3 = "";
    r = s->lengthOfLongestSubstring(t3);
    cout << r << endl;
    string t4 = "wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco";
    r = s->lengthOfLongestSubstring(t4);
    cout << r << endl;
    return 0;
}
