#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows == 0 || nRows == 1) {
            return s;
        }
        
        string r ("");
        vector<string> all_rows (nRows, "");
        int modal = nRows*2-2;
        for (int i = 0; i != s.size(); ++i) {
            int which_row = i % modal;
            if (which_row < nRows) {
                all_rows[which_row] += s[i];
            } else {
                all_rows[modal-which_row] += s[i];
            }
        }
        
        for (int i = 0; i != all_rows.size(); ++i) {
            r += all_rows[i];
        }
        return r;
    }
};

int main() {
    Solution *s = new Solution();
    string test;
    string r;

    test = "PAYPALISHIRING";
    r = s->convert(test, 3);
    cout << r << endl;

    test = "ABC";
    r = s->convert(test, 2);
    cout << r << endl;

    return 0;
}

