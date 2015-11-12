#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string commonString(string a, string b) {
        int i,j;
        string tmp;
        for (i = 0, j = 0; i != a.size(), j != b.size(); ++i, ++j) {
            if (a[i] == b[j]) {
                tmp += a[i];
            } else {
                break;
            }
        }
        return tmp;
    }

    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0) {
            return "";
        }
        string longest = strs[0];
        if (strs.size() > 1) {
            for (int i = 1; i != strs.size(); ++i) {
                longest = commonString(longest, strs[i]);
            }
        }
        
        return longest;
    }
};


int main() {
    Solution *s = new Solution();
    string test[] = {"abcde", "abcddiewer", "abcdsdflsdf"};
    vector<string> v(test, test + sizeof(test) / sizeof(string));
    string r = s->longestCommonPrefix(v);
    cout<< r << endl;

    v.clear();
    cout << v.size() << endl;
    r = s->longestCommonPrefix(v);
    cout << r << endl;

    v.clear();
    v.push_back("aca");
    v.push_back("cba");
    r = s->longestCommonPrefix(v);
    cout << r << endl;
    return 0;
}