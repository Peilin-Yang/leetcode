#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void swap(vector<int>& nums, int j, int k) {
      int tmp = nums[k];
      nums[k] = nums[j];
      nums[j] = tmp;
    }
    int firstMissingPositive(vector<int>& nums) {
      int s = 0;
      int e = nums.size();
      while (s < e) {
        if (s == nums[s]-1) {
          s++;
        }
        else if (nums[s] <= 0 || nums[s] > e || nums[s] == nums[nums[s]-1]) {
          swap(nums, s, --e);
        } else {
          swap(nums, s, nums[s]-1);
        }
      }
      return e+1;
    }
};

int main() {
  Solution s;
  //int a[] = {3,4,-1,1};
  int a[] = {1,1};
  vector<int> n(a, a+sizeof(a)/sizeof(int));
  cout << s.firstMissingPositive(n) << endl;;
  return 0;
}
