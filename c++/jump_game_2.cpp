#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int l = nums.size(), i = 0, j = 1, cnt = 0, mx;
        if (l == 1) return 0;
        while (i < l - 1 && i + nums[i] < l - 1) {
            for (mx = j; j <= i + nums[i]; j++) { mx = (mx + nums[mx] <= j + nums[j]) ? j : mx; }
            i = mx; cnt++;
            cout << "i:" << i << ",j:" << j << endl;
        }
        return ++cnt; /* One more step to last index. */
    }
};


int main() {
  Solution s;
  int a[] = {2,3,1,1,4};
  vector<int> n(a, a+sizeof(a)/sizeof(int));
  cout << s.jump(n) << endl;;

  return 0;
}
