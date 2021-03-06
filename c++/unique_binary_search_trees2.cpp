#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        if (n <= 0) return 0;
        vector<int> dp(n+1);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = 0;
            for (int j = 1; j <= i; j++) {
                dp[i] += dp[j-1]*dp[i-j];
            }
        }
        return dp[n];
    }
};

int main() {
    Solution *s = new Solution();

    cout << s->numTrees(3) << endl;

    return 0;
}

