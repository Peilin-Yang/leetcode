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
    int computSquares(vector<vector<char>>& grids) {
        if (grids.empty()) return 0;
        int n = grids.size(), m = grids[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        dp[0][0] = grids[0][0] == '0'?0:1;
        for (int i = 1; i < n; i++) {
            dp[i][0] = grids[i][0] == '0'?0:1;
        }
        for (int i = 1; i < m; i++) {
            dp[0][i] = grids[0][i] == '0'?0:1;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                dp[i][j] = grids[i][j] == '0'?0:1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
            }
        }
        int sum = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) 
                sum += dp[i][j];
        return sum;
    }
};

int main() {
  Solution s;
  
  string a[] = {"011", "011", "011"};
  vector<vector<char> > t;
  for (int i = 0; i < sizeof(a)/sizeof(string); i++) {
    vector<char> tmp;
    for (int j = 0; j < a[i].size(); j++) {
      tmp.push_back(a[i][j]);
    }
    t.push_back(tmp);
  }

  cout << s.computSquares(t) << endl;

  return 0;
}
