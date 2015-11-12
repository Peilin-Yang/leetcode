#include <iostream>
#include <climits>
#include <cstdlib>

using namespace std;


class Solution {
public:
    int atoi(string s) {
        int i = 0, l = s.size();
        while (s[i] == ' ' && i < l) i++;
        if (i == l || !(s[i]>'0' || s[i]<'9' || s[i]!='+' || s[i]!='-')) return 0;
        int neg = 1;
        long long r = 0;
        if (s[i] == '+' || s[i] == '-') {
            if (s[i] == '-') neg = -1;
            i++;
        }
        while (i < l && (s[i] >= '0' && s[i] <= '9')) {
            cout << i << " " << s[i] << endl;
            r = r*10+(s[i]-'0');
            cout << r << endl;
            if (r > INT_MAX) {
                if (neg == -1) return INT_MIN;
                return INT_MAX;
            }
            i++;
        }
        return r*neg;
    }
};

int main() {
    Solution *s = new Solution();
    string test("    10522545459");
    int r = s->atoi(test);

    cout << r << endl;
    cout << atoi(test.c_str()) << endl;

    //char *e = "";
    //cout << sizeof(e)/sizeof(char*) << endl;
    cout << INT_MAX << " " << (long long)INT_MAX+1 << " " << INT_MIN << endl;

    return 0;
}
