#include<iostream>
#include<vector>

using namespace std;
void p(vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ",";
    }
    cout << endl;
}

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int last_zero = -1, cur = 0;
        for (; cur < nums.size(); cur++) {
            cout << cur << endl;
            if (nums[cur] == 0) {
                if (last_zero == -1 || nums[last_zero] != 0) last_zero = cur;
            } else {
                swap(nums[cur], nums[last_zero++]);
            }
        }
    }
};

int main() {
  Solution s;
  
  vector<int> t = {0,2,0,0,5,3,0};
  s.moveZeroes(t);
  p(t);

  return 0;
}
