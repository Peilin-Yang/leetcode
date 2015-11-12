#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(const string s, const string p) {
        int sSize = s.size(), pSize = p.size();
        int sS = 0, pS = 0;
        int last_star_s = -1, last_star_p = -1;
        while (sS != sSize) {
            if (pS < pSize && (p[pS] == '?' || p[pS] == s[sS])) {
                sS++;
                pS++;
            } else if (pS < pSize && p[pS] == '*') {
                last_star_s = sS;
                last_star_p = pS++;
            } else if (last_star_p >= 0) {
                pS = last_star_p+1;
                sS = ++last_star_s;
            } else {
                return false;
            }
        }
        while (pS < pSize && p[pS] == '*') {
            pS++;
        }
        return pS == pSize;
    }
};

int main() {
    Solution *s = new Solution();
    bool r;
    string str;
    string re;

    str = "aa";
    re = "a";
    r = s->isMatch(str, re);
    cout << str << " " << re << " " << r << endl;

    str = "aa";
    re = "aa";
    r = s->isMatch(str, re);
    cout << str << " " << re << " " << r << endl;

    str = "aaa";
    re = "aa";
    r = s->isMatch(str, re);
    cout << str << " " << re << " " << r << endl;

    str = "aa";
    re = "*";
    r = s->isMatch(str, re);
    cout << str << " " << re << " " << r << endl;

    str = "aa";
    re = "a*";
    r = s->isMatch(str, re);
    cout << str << " " << re << " " << r << endl;

    str = "ab";
    re = "?*";
    r = s->isMatch(str, re);
    cout << str << " " << re << " " << r << endl;

    str = "aab";
    re = "c*a*b";
    r = s->isMatch(str, re);
    cout << str << " " << re << " " << r << endl;
    
    return 0;
}
