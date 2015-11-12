#include<vector>
#include<iostream>
#include<climits>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      int r = INT_MIN;
      int tmp_r = 0;
      int l = nums.size();
      for (int i = 0; i != l; i++) {
          tmp_r = tmp_r>=0?tmp_r+nums[i]:nums[i];
          r = max(tmp_r, r);
      }
      return r;    
    }
};


int main() {
  Solution s;

  int a[] = {1,5};
  vector<int> n(a, a+sizeof(a)/sizeof(int));
  cout << s.maxSubArray(n) << endl;
}
