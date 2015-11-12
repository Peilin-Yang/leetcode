#include<iostream>
#include<vector>

using namespace std;

void print_solution(vector<vector<bool> >& flags) {
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
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.size(), l2 = s2.size(), l3 = s3.size();
        if (l1+l2 != l3) return false;
        vector<vector<bool> > dp(l1+1, vector<bool>(l2+1, false));
        dp[0][0] = s3[0] == s1[0] || s3[0] == s2[0];
        if (!dp[0][0]) return false;
        for (int i = 1; i <= l1; i++) {
            if (s3[i-1] == s1[i-1] && dp[i-1][0]) dp[i][0] = true;
        }
        for (int i = 1; i <= l2; i++) {
            if (s3[i-1] == s2[i-1] && dp[0][i-1]) dp[0][i] = true;
        }
        for (int i = 1; i <= l1; i++) {
            for (int j = 1; j <= l2; j++) {
                dp[i][j] = (dp[i-1][j] && (s3[i+j-1] == s1[i-1])) || (dp[i][j-1] && (s3[i+j-1] == s2[j-1]));
            }
        }
        print_solution(dp);
        return dp[l1][l2];
    }

};


int main() {
  Solution s;

  string s1,s2,s3;

  /*
  s1 = "asdf";
  s2 = "hjkl";
  s3 = "asdfhjkl";
  cout << "s1:" << s1 << ",s2:" << s2 << ",s3:" << s3 << ", is:" << s.isInterleave(s1, s2, s3) << endl;

  s1 = "asdf";
  s2 = "jljlk";
  s3 = "ajljsdlfa";
  cout << "s1:" << s1 << ",s2:" << s2 << ",s3:" << s3 << ", is:" << s.isInterleave(s1, s2, s3) << endl;

  s1 = "aabd";
  s2 = "abdc";
  s3 = "aabdabdc";
  cout << "s1:" << s1 << ",s2:" << s2 << ",s3:" << s3 << ", is:" << s.isInterleave(s1, s2, s3) << endl;
  
  s1 = "aabd";
  s2 = "abdc";
  s3 = "aabdabcd";
  cout << "s1:" << s1 << ",s2:" << s2 << ",s3:" << s3 << ", is:" << s.isInterleave(s1, s2, s3) << endl;

  s1 = "aabc";
  s2 = "abad";
  s3 = "aabcbaad";
  cout << "s1:" << s1 << ",s2:" << s2 << ",s3:" << s3 << ", is:" << s.isInterleave(s1, s2, s3) << endl;
  */

  s1 = "aa";
  s2 = "ab";
  s3 = "aaba";
  cout << "s1:" << s1 << ",s2:" << s2 << ",s3:" << s3 << ", is:" << s.isInterleave(s1, s2, s3) << endl;

}

