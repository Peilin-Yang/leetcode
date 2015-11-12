#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = nums.size();
        int start = 0, end = l-1;
        while(start <= end) {
            int mid = (start+end)/2;
            if (nums[mid] == target) return true;
            if (nums[start] < nums[mid]) {
                if (target >= nums[start] && target < nums[mid]) end=mid-1;
                else start=mid+1;
            } else if (nums[start] > nums[mid]) {
                if (target > nums[mid] && target <= nums[end]) start=mid+1;
                else end=mid-1;
            } else start++;
        }
        
        return false;
    }
};

int main() {
  Solution s;
  
  //int a[] = {1,1,1,5,1,1,1,1,1,1,1};
  int a[] = {3,5,1};
  vector<int> n(a, a+sizeof(a)/sizeof(int));

  cout << std::boolalpha << s.search(n, 1) << endl;

  return 0;
}
