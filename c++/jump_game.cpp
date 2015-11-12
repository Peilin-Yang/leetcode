#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool a(vector<int> &nums, int idx) {
        if (idx == 0) return true;
        for (int i = idx-1; i >= 0; i--) {
            if (nums[i] >= idx-i && a(nums, i)) return true;
        }
        return false;
    }
    bool canJump(vector<int>& nums) {
        int l = nums.size();
        if (l <= 1) return true;
        return a(nums, l-1);
    }
};


int main() {
  Solution s;
  int a[] = {5,9,3,2,1,0,2,3,3,1,0,0};
  //int a[] = {1,1};
  //int a[] = {1,0,2};
  vector<int> n(a, a+sizeof(a)/sizeof(int));
  cout << std::boolalpha << s.canJump(n) << endl;;

  return 0;
}
