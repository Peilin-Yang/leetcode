#include <iostream>
#include <vector>
#include <climits>

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

void print_dp(vector<vector<pair<int, int> > >& dp) {
  //cout << "i:" << flags.size() << endl;
  for(int i = 0; i != dp.size(); i++) {
    //cout << "j:" << flags[i].size() << endl;
    for(int j = 0; j != dp[i].size(); j++) {
      cout << dp[i][j].first << "," << dp[i][j].second << " ";
    }
    cout << endl;
  }
}

class Solution {
public:
    int calculateMinimumHP(vector<vector<int> >& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int> > dp(m+1, vector<int>(n+1, INT_MAX)); 
        dp[m][n-1] = 1;
        dp[m-1][n] = 1;
        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                int required = min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j];
                dp[i][j] = required <= 0 ? 1 : required;
            }
        }
        return dp[0][0];
    }
};

int main() {
  Solution s;
  
  vector<vector<int> > t;
  vector<int> tt;
  tt.push_back(1);
  tt.push_back(-3);
  tt.push_back(3);
  t.push_back(tt);
  tt.clear();
  tt.push_back(0);
  tt.push_back(-2);
  tt.push_back(0);
  t.push_back(tt);
  tt.clear();
  tt.push_back(-3);
  tt.push_back(-3);
  tt.push_back(-3);
  t.push_back(tt);
  tt.clear();

  print_m(t);
  cout << s.calculateMinimumHP(t) << endl;

  return 0;
}
