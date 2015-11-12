#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = nums.size();
        int start = 0, end = l-1;
        while (start <= end) {
            int mid = (start+end)/2;
            if (nums[mid] == target) return mid;
            if (nums[mid] > target) end = mid-1;
            else start = mid+1;
        }
        return start;
    }
};

int main() {
  Solution s;
  
  int a[] = {1,3,5,6};
  vector<int> n(a, a+sizeof(a)/sizeof(int));

  cout << s.searchInsert(n, 5) << endl;
  cout << s.searchInsert(n, 2) << endl;
  cout << s.searchInsert(n, 7) << endl;
  cout << s.searchInsert(n, 0) << endl;

  return 0;
}
