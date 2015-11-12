#include <iostream>
#include <vector>

using namespace std;

bool _print = true;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
        int m = obstacleGrid.size();
        if (m == 0) return 0;
        int n = obstacleGrid[0].size();
        vector<vector<int> > dp(m, vector<int>(n, 0));
        for (int i = 0; i != m; i++) {
            for (int j = 0; j != n; j++) {
                if (obstacleGrid[i][j] == 0) dp[i][j] = 1;
            }
        }
        for (int i = 1; i != m; i++) {
            for (int j = 1; j != n; j++) {
                if (obstacleGrid[i][j] == 0) dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];        
    }
};

int main() {
    Solution *s = new Solution();
    int row1[] = {0,0,0};
    int row2[] = {0,1,0};
    int row3[] = {0,0,0};

    vector<int> v1 (row1, row1+ sizeof(row1) / sizeof(int) );
    vector<int> v2 (row2, row2+ sizeof(row2) / sizeof(int) );
    vector<int> v3 (row3, row3+ sizeof(row3) / sizeof(int) );

    vector<vector<int> > test;
    test.push_back(v1);
    test.push_back(v2);
    test.push_back(v3);

    int r;
    r = s->uniquePathsWithObstacles(test);
    cout << r << endl;

    return 0;
}

