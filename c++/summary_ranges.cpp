#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_r(vector<string>& r) {
  for (int i = 0; i != r.size(); i++) 
      cout << r[i] << ",";
    cout << endl;
}

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if (nums.empty()) return res;
        int start = 0, i = 1;
        string tmp;
        for (; i <= nums.size(); i++) {
            if (i == nums.size() || (i < nums.size() && (long)nums[i]-(long)nums[i-1]>1)) {
                if (i-start == 1) tmp = to_string(nums[start]);
                else tmp = to_string(nums[start])+"->"+to_string(nums[i-1]);
                res.push_back(tmp);
                start = i;
            }
        }
        
        return res;
    }
};

int main() {
  Solution s;
  
  //vector<int> t = {0,1,2,4,5,7};
  //vector<int> t = {1,4};
  vector<int> t = {-2147483648,-2147483647,2147483647};
  vector<string> r = s.summaryRanges(t);
  print_r(r);

  return 0;
}
