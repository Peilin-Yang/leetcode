#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      int l = nums.size();
      int tmp_location = 0;

      if (l == 0 || l == 1) return l;

      for (int i = 1; i != l; i++) {
        if (nums[i] == nums[tmp_location]) continue;
        tmp_location++;
        nums[tmp_location] = nums[i];
      }

      return tmp_location+1;
    }
};

int main() {
  Solution s;

  int a[] = {1,1,2,2,3,4,5,6,7};
  vector<int> n(a, a+sizeof(a)/sizeof(int));

  cout << s.removeDuplicates(n) << endl;
  for (int i = 0; i != n.size(); i++) {
    cout << n[i] << ",";
  }
  cout << endl;
  return 0;
}
