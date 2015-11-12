#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
      vector<int> ret;
      int l = nums.size();
      int start = 0, end = l-1;
      int found_idx = -1;
      while(start <= end) {
        int mid = (start+end)/2;
        if (nums[mid] == target) {
          found_idx = mid;
          break;
        }
        if (nums[mid] > target) {
          end = mid - 1;
        } else {
          start = mid + 1;
        }
      }
      cout << "found_idx:" << found_idx << endl;
      if (found_idx == -1) {
        ret.push_back(-1);
        ret.push_back(-1);
      } else {
        int start_idx = found_idx, end_idx = found_idx;
        while( (start_idx - 1 >= 0 && nums[start_idx-1]==target) || (end_idx + 1 < l && nums[end_idx+1]==target) ) {
          if (start_idx - 1 >= 0 && nums[start_idx-1]==target) start_idx--;
          if (end_idx + 1 < l && nums[end_idx+1]==target) end_idx++;
        }
        ret.push_back(start_idx);
        ret.push_back(end_idx);
      }
      return ret;
    }
};

int main() {
  Solution s;
  
  //int a[] = {5,7,7,8,8,10};
  int a[] = {1};
  vector<int> n(a, a+sizeof(a)/sizeof(int));

  vector<int> r = s.searchRange(n, 1);

  for (int i = 0; i != r.size(); i++) {
    cout << r[i] << ",";
  }
  cout << endl;

  return 0;
}
