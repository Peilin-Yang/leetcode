#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void print_m(vector<vector<int> >& flags) {
  //cout << "i:" << flags.size() << endl;
  for(int i = 0; i != flags.size(); i++) {
    //cout << "j:" << flags[i].size() << endl;
    for(int j = 0; j != flags[i].size(); j++) {
      cout << flags[i][j] << ",";
    }
    cout << endl;
  }
}


class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<pair<int, int> > > dp(m, vector<int>(n, make_pair(0, 0))); // first is the required HP, second is the current HP
        dp[0][0] = make_pair(dungeon[0][0] >=0 ? 1 : 1-dungeon[0][0], dungeon[0][0] >=0 ? 1+dungeon[0][0] : 1);
        for (int i = 1; i < m; i++) {
            int diff = dp[i-1][0].second+dungeon[i][0];
            int required = diff > 0 ? 0 : 1-diff;
            int remain = diff > 0 ? diff : 1;
            dp[i][0] = make_pair(required, remain);
        }
        for (int i = 1; i < n; i++) {
            int diff = dp[0][i-1].second+dungeon[0][i];
            int required = diff > 0 ? 0 : 1-diff;
            int remain = diff > 0 ? diff : 1;
            dp[0][i] = make_pair(required, remain);
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                int diff = max(dp[i-1][j].second, dp[i][j-1].second) + dungeon[i][j];
                int required = diff > 0 ? 0 : 1-diff;
                int remain = diff > 0 ? diff : 1;
                dp[i][j] = make_pair(required, remain);
            }
        }
        return dp[m-1][n-1];
    }
};

int main() {
  Solution s;
  
  vector<vector<int> > t;
  vector<int> tt;
  tt.push_back(-2);
  tt.push_back(-3);
  tt.push_back(3);
  t.push_back(tt);
  tt.clear();
  tt.push_back(-5);
  tt.push_back(-10);
  tt.push_back(1);
  t.push_back(tt);
  tt.clear();
  tt.push_back(10);
  tt.push_back(30);
  tt.push_back(-5);
  t.push_back(tt);
  tt.clear();

  print_m(t);
  cout << s.calculateMinimumHP(t) << endl;

  return 0;
}
