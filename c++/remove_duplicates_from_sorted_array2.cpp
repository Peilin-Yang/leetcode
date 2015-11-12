#include<vector>
#include<iostream>

using namespace std;

void print_v(vector<int>& v) {
  for(int i = 0; i < v.size(); i++) {
    cout << v[i] << ",";
  }
  cout << endl;
}

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = nums.size();
        if (l < 2) return l;
        int cur = nums[0] == nums[1] ? 1 : 0;
        for (int i = cur+1; i < l; i++) {
            if (nums[cur] != nums[i]) {
                nums[++cur] = nums[i];
                if (i+1 < l && nums[i+1]==nums[i]) {
                    nums[++cur] = nums[i];
                    i++;
                }
            }
            print_v(nums);
        }
        return cur+1;
    }
};

int main() {
  Solution s;

  int a[] = {1,1,1,2,2,3,4,5,5,5,6,7,7,7};
  vector<int> n(a, a+sizeof(a)/sizeof(int));

  print_v(n);
  cout << s.removeDuplicates(n) << endl;
  print_v(n);
  return 0;
}
