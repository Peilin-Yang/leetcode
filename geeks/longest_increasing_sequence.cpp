#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int bs(vector<int> &a, int key) {
        int start = 0, end = a.size()-1;
        while (start <= end) {
            int mid = start+(end-start)/2;
            if (a[mid] == key) return mid;
            if (a[mid] < key) start = mid+1;
            else end = mid-1;
        }
        return start;
    }
    int lis(vector<int>& nums) {
        if (nums.empty()) return 0;
        int l = nums.size();
        vector<int> tails(1, nums[0]);
        for (int i = 1; i < l; i++) {
            if (nums[i] < tails[0]) tails[0] = nums[i];
            else if (nums[i] > tails.back()) tails.push_back(nums[i]);
            else tails[bs(tails, nums[i])] = nums[i];
        }
        return tails.size();
    }
};

int main() {
  Solution s;

  int a[] = {5,2,3,7,11,8,10,13,6,9};
  vector<int> n(a, a+sizeof(a)/sizeof(int));

  cout << s.lis(n) << endl;
  return 0;
}
