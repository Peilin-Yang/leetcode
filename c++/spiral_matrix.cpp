#include <iostream>
#include <vector>

using namespace std;

bool _print = true;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> r;
        int m = matrix.size();
        if (m == 0) return r;
        int n = matrix[0].size();
        int up = 0, down = m-1, left = 0, right = n-1;
        while (up<=down && left<=right) {
            for (int i = left; i <= right; i++) {
                r.push_back(matrix[up][i]);
            }
            up++;
            for (int i = up; i <= down; i++) {
                r.push_back(matrix[i][right]);
            }
            right--;
            if (up <= down) {
                for (int i = right; i >= left; i--) {
                    r.push_back(matrix[down][i]);
                }
            }
            down--;
            if (left <= right) {
                for (int i = down; i >= up; i--) {
                    r.push_back(matrix[i][left]);
                }
            }
            left++;
        }
        return r;
    }
};

int main() {
    Solution *s = new Solution();
    int row1[] = {16,2,77,29};
    int row2[] = {61,123,87,35};
    int row3[] = {5,12,643,934};

    vector<int> v1 (row1, row1+ sizeof(row1) / sizeof(int) );
    vector<int> v2 (row2, row2+ sizeof(row2) / sizeof(int) );
    vector<int> v3 (row3, row3+ sizeof(row3) / sizeof(int) );

    vector<vector<int> > test;
    test.push_back(v1);
    test.push_back(v2);
    test.push_back(v3);

    vector<int> r;
    r = s->spiralOrder(test);

    for (int i = 0; i != r.size(); ++i) {
        cout << r[i] << ",";
    }

    cout << endl;

    return 0;
}

