#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>

using namespace std;

bool _print = true;

class Solution {
public:
    bool isValid(string s) {
        if (s.size() == 3 || s.size() == 2) {
            if (s[0] == '0' || atoi(s.c_str()) == 0 || atoi(s.c_str()) > 255) {
                return false;
            }
        }
        return true;  
    }

    void dfs(string s, string tmp_r, vector<string>& r, int remain_len) {
        if (remain_len == 0) {
            if (s.size() == 0) { r.push_back(tmp_r); }
            return;
        }
        for (int i = 1; i <= 3; ++i) {
            if (s.size() >= i && isValid(s.substr(0, i))) {
                if (remain_len == 4) {
                    dfs(s.substr(i), tmp_r+s.substr(0, i), r, remain_len-1);
                } else {
                    dfs(s.substr(i), tmp_r+"."+s.substr(0, i), r, remain_len-1);
                }
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> r;
        dfs(s, "",  r, 4);
        return r;
    }
};

int main() {
    Solution *s = new Solution();
    string t1;
    vector<string> r;

    t1 = "25525511135";
    r = s->restoreIpAddresses(t1);
    for (int i = 0; i != r.size(); ++i) {
        cout << r[i] << " ";
    }
    cout << endl;

    t1 = "0012835";
    r = s->restoreIpAddresses(t1);
    for (int i = 0; i != r.size(); ++i) {
        cout << r[i] << " ";
    }
    cout << endl;
    return 0;
}

