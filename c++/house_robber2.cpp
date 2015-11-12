#include <iostream>
#include <vector>

using namespace std;

void p(vector<int>& v) {
  for (int i = 0; i<v.size(); i++) {
    cout << v[i] << ",";
  }
  cout << endl;
}

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        int res = nums[0];
        vector<int> dp1(n, 0);
        vector<int> dp2(n, 0);
        dp1[0] = nums[0];
        if (n > 1) {
            dp1[1] = nums[1];
            dp2[1] = nums[1];
            res = max(res, nums[1]);
        }
        for (int i = 2; i < n; i++) {
            for (int j = 0; j < i-1; j++) {
                dp1[i] = max(dp1[i], dp1[j]+nums[i]);
                dp2[i] = max(dp2[i], dp2[j]+nums[i]);
                if (i == n-1) res = max(res, dp2[i]);
                else res = max(res, dp1[i]);
            }
        }
        p(dp1);
        p(dp2);
        return res;
    }
};


int main() {
  Solution s;

  vector<int> t = {4,1,2,7,5,3,1};
  cout << s.rob(t) << endl;

  return 0;
}
