#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        std::sort(nums.begin(), nums.end());
        int s = nums.size();
        int closest = target < 0 ? INT_MIN : INT_MAX;
        for(int i = 0; i <= s-3; ++i) {
            int c = target - nums[i];
            int start = i + 1, end = s - 1;
            while (start < end) {
                int tmp = nums[start]+nums[end]+nums[i];
                if (abs(tmp-target) < abs(closest-target)) {
                    closest = tmp;
                }
                cout << tmp << " " << closest << endl;
                if (nums[start]+nums[end] < c) {
                    start++;
                } else if (nums[start]+nums[end] > c) {
                    end--;
                } else {
                    return target;
                }
            }
        }
        return closest;
    }
};

int main() {
  Solution s;
  
  //int myints[] = {-1,2,1,-4};
  //int myints[] = {1,1,1,0};
  int myints[] = {-3,-2,-5,3,-4};
  std::vector<int> a(myints, myints + sizeof(myints) / sizeof(int) );
  int r = s.threeSumClosest(a, -1);
  cout << r << endl;

  return 0;
}
