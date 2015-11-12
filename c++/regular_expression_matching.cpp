#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool a(const string s, const string p, int sS, int pS) {
        int sSize = s.size(), pSize = p.size();
        if (pS == pSize) return sS == sSize;
        if (p[pS+1] == '*') {
            if (a(s,p,sS,pS+2)) return true;
            while(sS < sSize && (s[sS] == p[pS] || p[pS] == '.')) {
                if (a(s,p,++sS,pS+2)) return true;
            }
        } else {
            if (sS < sSize && (s[sS] == p[pS] || p[pS] == '.')) return a(s,p,sS+1,pS+1);
        }
        return false;
    }
    bool isMatch(const string s, const string p) {
      return a(s,p,0,0);
    }
};

int main() {
    Solution *s = new Solution();
    bool r;
    string str;
    string re;

    str = "";
    re = ".";
    r = s->isMatch(str, re);
    cout << str << " " << re << " " << r << endl;

    str = "aasdfasdfasdfasdfas";
    re = "aasdf.*asdf.*asdf.*asdf.*s";
    r = s->isMatch(str, re);
    cout << str << " " << re << " " << r << endl;

    str = "a";
    re = "ab*c";
    r = s->isMatch(str, re);
    cout << str << " " << re << " " << r << endl;

    str = "a";
    re = "ab*a";
    r = s->isMatch(str, re);
    cout << str << " " << re << " " << r << endl;

    str = "a";
    re = ".";
    r = s->isMatch(str, re);
    cout << str << " " << re << " " << r << endl;

    str = "aaa";
    re = "ab*.*.*a";
    r = s->isMatch(str, re);
    cout << str << " " << re << " " << r << endl;

    str = "aaa";
    re = "ab*.*.*b";
    r = s->isMatch(str, re);
    cout << str << " " << re << " " << r << endl;

    str = "aaa";
    re = "ab*a*c*a";
    r = s->isMatch(str, re);
    cout << str << " " << re << " " << r << endl;
    
    str = "aaa";
    re = "a*a";
    r = s->isMatch(str, re);
    cout << str << " " << re << " " << r << endl;

    str = "aaa";
    re = "aaaa";
    r = s->isMatch(str, re);
    cout << str << " " << re << " " << r << endl;

    str = "aaa";
    re = "aa";
    r = s->isMatch(str, re);
    cout << str << " " << re << " " << r << endl;

    str = "aa";
    re = "aa";
    r = s->isMatch(str, re);
    cout << str << " " << re << " " << r << endl;

    str = "aa";
    re = "a*";
    r = s->isMatch(str, re);
    cout << str << " " << re << " " << r << endl;

    str = "";
    re = "";
    r = s->isMatch(str, re);
    cout << str << " " << re << " " << r << endl;

    str = "";
    re = "a*";
    r = s->isMatch(str, re);
    cout << str << " " << re << " " << r << endl;

    str = "";
    re = ".*";
    r = s->isMatch(str, re);
    cout << str << " " << re << " " << r << endl;

    str = "abc";
    re = "abc.*";
    r = s->isMatch(str, re);
    cout << str << " " << re << " " << r << endl;

    str = "abc";
    re = "abcd*";
    r = s->isMatch(str, re);
    cout << str << " " << re << " " << r << endl;

    str = "abchjgjgdgjhgdh";
    re = "abc.*";
    r = s->isMatch(str, re);
    cout << str << " " << re << " " << r << endl;

    str = "abc";
    re = "abc.*a";
    r = s->isMatch(str, re);
    cout << str << " " << re << " " << r << endl;

    return 0;
}
