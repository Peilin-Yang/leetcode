#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int search_pivot(vector<int>& nums, int start, int end) {
      cout << "search_pivot -- start:" << start << ",end:" << end << endl;
      int ret = -1;
      int l = end-start+1;
      if(l <= 1) return -1;
      if (l == 2) {
        if (nums[start] > nums[end]) {
          return start;
        } else {
          return -1;
        }
      }
      int mid = l%2 == 0 ? l/2-1 : l/2;
      if (nums[start+mid] > nums[start+mid+1]) return start+mid;
      ret = search_pivot(nums, start, start+mid);
      return ret == -1 ? search_pivot(nums, start+mid+1, end) : ret;
    }

    int search_via_pivot(vector<int>& nums, int target, int start, int end) {
      cout << "search_via_pivot -- start:" << start << ",end:" << end << endl;
      int l = end-start+1;
      if (l == 1 && target != nums[start]) return -1;
      int mid = l%2 == 0 ? l/2-1 : l/2;
      if (target == nums[start+mid]) return start+mid;
      if (target < nums[start+mid]) return search_via_pivot(nums, target, start, start+mid);
      if (target > nums[start+mid]) return search_via_pivot(nums, target, start+mid+1, end);
    }

    int search(vector<int>& nums, int target) {
      int l = nums.size();
      int mid = l%2 == 0 ? l/2-1 : l/2;
      int pivot = search_pivot(nums, 0, l-1);
      cout << "pivot:" << pivot << endl;
      int start = 0, end = l-1;
      if (pivot == -1) return search_via_pivot(nums, target, start, end);
      if (target >= nums[start] && target <= nums[pivot]) {
        end = pivot;
      } else if (pivot+1 < l && target >= nums[pivot+1] && target <= nums[end]) {
        start = pivot+1;
      } else {
        return -1;
      }
      return search_via_pivot(nums, target, start, end);
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

  cout << s.search(n, 1) << endl;

  return 0;
}
