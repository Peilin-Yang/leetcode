#include <iostream>
#include <vector>

using namespace std;

bool _print = true;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > r(n, vector<int>(n, 0));
        int cur = 1;
        int up = 0, down = n-1, left = 0, right = n-1;
        while (up <= down && left <= right) {
            for (int i = left; i <= right; i++) {
                r[up][i] = cur++;
            }
            up++;
            for (int i = up; i <= down; i++) {
                r[i][right] = cur++;
            }
            right--;
            if (up<=down) {
                for (int i = right; i >= left; i--) {
                    r[down][i] = cur++;
                }
            }
            down--;
            if (left<=right) {
                for (int i = down; i>= up; i--) {
                    r[i][left] = cur++;
                }
            }
            left++;
        }
        return r;
    }
};

int main() {
    Solution *s = new Solution();
    vector<vector<int> > r = s->generateMatrix(3);

    for (int i = 0; i != r.size(); ++i) {
        for (int j = 0; j != r[i].size(); j++) {
            cout << r[i][j] << ",";
        }
        cout << endl;
    }

    cout << endl;

    return 0;
}

