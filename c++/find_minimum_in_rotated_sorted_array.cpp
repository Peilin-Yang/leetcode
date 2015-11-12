#include <vector>
#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0, end = nums.size()-1;
        int res = INT_MAX;
        while (start <= end) {
            int mid = start + (end - start)/2;
            if (nums[start] <= nums[mid]) { 
                res = min(res, nums[start]);
                start = mid+1;
            }
            else {
                res = min(res, nums[mid]);
                end = mid-1;
            }
        }
        return res;
    }
};

int main() {
  Solution s;
  
  //int a[] = {4,5,6,7,0,1,2,3};
  //int a[] = {1,2,3,4,5,6,7,0};
  //int a[] = {1};
  //int a[] = {7,8,1,2,3,4,5,6};
  int a[] = {2,3,4,5,6,7,1};
  vector<int> n(a, a+sizeof(a)/sizeof(int));

  cout << s.findMin(n) << endl;

  return 0;
}
