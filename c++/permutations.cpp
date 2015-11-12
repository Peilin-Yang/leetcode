#include <vector>
#include <iostream>

using namespace std;

void print_v(vector<int> & v) {
  for (int i = 0; i != v.size(); i++) {
    cout << v[i] << ",";
  }
  cout << endl;
}


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
    void helper(vector<int> nums, vector<vector<int> >& res, int start) {
        if (start >= nums.size()) {
            res.push_back(nums);
            return;
        }
        for (int i = start; i != nums.size(); i++) {
            std::swap(nums[i], nums[start]);
            helper(nums, res, start+1);
        }
    }
    vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int> > res;
        helper(nums, res, 0);
        return res;
    }
};


int main() {
  Solution s;
  
  int a[] = {1,2,3};
  vector<int> n(a, a+sizeof(a)/sizeof(int));

  vector<vector<int> > r = s.permute(n);

  print_r(r);

  return 0;
}
