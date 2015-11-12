#include <iostream>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int start = 0, r_start, len = INT_MAX, cur_sum = 0;
        int l = nums.size();
        for (int i = 0; i < l; i++) {
            cur_sum += nums[i];
            if (cur_sum >= s) {
                cout << "111" << endl;
                while (start <= i) {
                    cur_sum -= nums[start];
                    if (cur_sum < s) {
                        cur_sum += nums[start];
                        break;
                    }
                    start++;
                }
                len = min(len, i-start+1);
            }
        }
        return len==INT_MAX?0:len;
    }
};

int main() {
  Solution s;

  vector<int> t = {2,3,1,2,4,3};
  cout << s.minSubArrayLen(7, t) << endl;

  return 0;
}
