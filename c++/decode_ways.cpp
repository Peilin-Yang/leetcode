#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) return 0;
        int r1,r2;
        r1 = r2 = s[0] == '0'?0:1;
        int l = s.size();
        for (int i = 1; i < l; i++) {
            if (s[i] == '0') r1 = 0;
            if (s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6')) {
                r1 = r1+r2;
                r2 = r1-r2;
            } else r2 = r1;
        }
        return r1;
    }
};

int main() {
    Solution *s = new Solution();

    string test("17");
    cout << s->numDecodings(test) << endl;

    return 0;
}

