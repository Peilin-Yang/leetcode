#include <iostream>
#include <vector>

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
    int minPathSum(vector<vector<int> >& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        vector<vector<int> > dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];
        for (int i = 0; i != m; i++) {
            for (int j = 0; j != n; j++) {
                if (i == 0 && j == 0) continue;
                if (i-1>=0 && j-1>=0) {
                    dp[i][j] = grid[i][j]+std::min(dp[i-1][j], dp[i][j-1]);
                } else if (i-1>=0) {
                    dp[i][j] = grid[i][j]+dp[i-1][j];
                } else {
                    dp[i][j] = grid[i][j]+dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};

int main() {
    Solution *s = new Solution();
    int row1[] = {1,2};
    int row2[] = {1,1};

    vector<int> v1 (row1, row1+ sizeof(row1) / sizeof(int) );
    vector<int> v2 (row2, row2+ sizeof(row2) / sizeof(int) );

    vector<vector<int> > test;
    test.push_back(v1);
    test.push_back(v2);

    int r;
    r = s->minPathSum(test);
    cout << r << endl;

    return 0;
}

