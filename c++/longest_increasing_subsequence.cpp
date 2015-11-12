#include <vector>
#include <iostream>
using namespace std;

void p(vector<int>& v) {
  for (int i = 0; i < v.size(); i++) cout << v[i] << ",";
  cout << endl;
}

class Solution {
public:
    int bs(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1;
        while (start <= end) {
            int mid = start+(end-start)/2;
            if (nums[mid] == target) return mid;
            if (nums[mid] > target) end = mid-1;
            else start = mid+1;
        }
        return start;
    }
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<int> res;
        res.push_back(nums[0]);
        int l = nums.size();
        for (int i = 1; i < l; i++) {
            if (nums[i] < res[0]) res[0] = nums[i];
            else if (nums[i] > res.back()) res.push_back(nums[i]);
            else res[bs(nums, nums[i])] = nums[i];
        }
        return res.size();
    }
};


int main() {
    Solution *s = new Solution();
    int test[] = {10,9,2,5,3,7,101,18};
    vector<int> v(test, test + sizeof(test) / sizeof(int));
    cout << s->lengthOfLIS(v) << endl;
    return 0;
}
