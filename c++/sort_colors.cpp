#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void swap(vector<int>& nums, int i, int j) {
      int tmp = nums[i];
      nums[i] = nums[j];
      nums[j] = tmp;
    }

    void sortColors(vector<int>& nums) {
      int l = nums.size();
      int first_non_0 = 0;
      int first_2 = l-1;
      while(nums[first_2] == 2) {
        first_2--;
      }
      while(nums[first_non_0] == 0) {
        first_non_0++;
      }
      int start = first_non_0;
      int end = first_2;
      while (start <= end) {
        cout << "start:" << start << endl;
        if (nums[start] == 2) {
          swap(nums, start, end--);
          while(nums[end] == 2) end--;
          if (first_non_0 == start) {
            while(nums[start] == 0) {
              start++;
              first_non_0++;
            }
          }
        } else if (nums[start] == 1) {
          start++;
        } else if (nums[start] == 0) {
          swap(nums, start, first_non_0++);
        }
      }
    }
};

int main() {
  Solution s;

  //int a[] = {0,1,2,2,1,1,1,2,0,0,1,2,0,2,1};
  //int a[] = {2,0,0};
  int a[] = {1,2,0};
  vector<int> n(a, a+sizeof(a)/sizeof(int));
  for (int i = 0; i != n.size(); i++) {
    cout << n[i] << ",";
  }
  cout << endl;
  
  s.sortColors(n);
  for (int i = 0; i != n.size(); i++) {
    cout << n[i] << ",";
  }
  cout << endl;
  return 0;
}
