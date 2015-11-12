#include <iostream>
#include <vector>
#include <climits>

using namespace std;

bool _print = true;

void print_r(vector<vector<int> >& r) {
  for (int i = 0; i != r.size(); i++) {
    for (int j = 0; j != r[i].size(); j++) {
      cout << r[i][j] << ",";
    }
    cout << endl;
  }
}

class Solution {
public:
    int minimumTotal(vector<vector<int> >& triangle) {
        int m = triangle.size();
        if(m == 0) return 0;
        int n = triangle[m-1].size();
        vector<vector<int> > dp(m, vector<int>(n, INT_MAX));
        dp[0][0] = triangle[0][0];
        for (int i = 1; i != m; i++) {
            for (int j = 0; j != triangle[i].size(); j++) {
                if (j > 0 && j < triangle[i].size()) {
                    dp[i][j] = triangle[i][j] + min(dp[i-1][j-1], dp[i-1][j]);
                } else if (j == 0){
                    dp[i][j] = triangle[i][j] + dp[i-1][j];
                } else {
                    dp[i][j] = triangle[i][j] + dp[i-1][j-1];
                }
            }
        }
        int r = INT_MAX;
        for (int i = 0; i != n; i++) {
            r = min(r, dp[m-1][i]);
        }
print_r(dp);
        return r;
    }
};

int main() {
    Solution *s = new Solution();
    int row1[] = {-1};
    int row2[] = {3,2};
    int row3[] = {1,-2,-1};

    vector<int> v1 (row1, row1+ sizeof(row1) / sizeof(int) );
    vector<int> v2 (row2, row2+ sizeof(row2) / sizeof(int) );
    vector<int> v3 (row3, row3+ sizeof(row3) / sizeof(int) );

    vector<vector<int> > test;
    test.push_back(v1);
    test.push_back(v2);
    test.push_back(v3);

    int r;
    r = s->minimumTotal(test);
    cout << r << endl;

    return 0;
}

