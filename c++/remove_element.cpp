#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void swap(vector<int>& nums, int i, int j) {
      int tmp = nums[i];
      nums[i] = nums[j];
      nums[j] = tmp;
    }
    int removeElement(vector<int>& nums, int val) {
      int l = nums.size();
      int start = 0;
      int end = l-1;
      while(start <= end) {
        if (nums[start] == val) {
          swap(nums, start, end);
          while(nums[end] == val) end--;
        } else {
          start++;
        }
      }
      cout << "end:" << end << endl;
      return start;
    }
};


int main() {
  Solution s;

  int a[] = {1,2,3,4,2,3,4,2,4,5,6,7,2,3,4,5,6,1};
  //int a[] = {};
  vector<int> n(a, a+sizeof(a)/sizeof(int));

  cout << s.removeElement(n, 2) << endl;
  for(int i = 0; i != n.size(); i++) {
    cout << n[i] << ",";
  }
  cout << endl;

  return 0;
}
