#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void print_v(vector<int> & v) {
  for (int i = 0; i != v.size(); i++) {
    cout << v[i] << ",";
  }
  cout << endl;
}

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int l = nums.size();
        if (l == 0 || l == 1) return;
        int last_ascending = -1;
        int p1=0,p2=1;
        while(p2 != l) {
            if (nums[p1] < nums[p2]) {
                cout << "p1 < p2 -- p1:" << p1 << " p2:" << p2 << endl;
                last_ascending = p1;
            }
            p1++;
            p2++;
        }
        int last_bigger_than = l-1;
        if (last_ascending != -1) {
            while (last_bigger_than != last_ascending) {
                if (nums[last_bigger_than] > nums[last_ascending]) break;
                last_bigger_than--;
            }
            std:swap(nums[last_ascending], nums[last_bigger_than]);
        }
        cout << "last_ascending:" << last_ascending << " last_bigger_than:" << last_bigger_than << endl;
        std::sort(nums.begin()+last_ascending+1, nums.end());
    }
};


int main() {
  Solution s;
  
  //int a[] = {1,2,3};
  //int a[] = {3,2,1};
  //int a[] = {1,1,5};
  //int a[] = {1,3,2};
  //int a[] = {1,4,6,5};
  int a[] = {2,3,1};
  vector<int> n(a, a+sizeof(a)/sizeof(int));

  s.nextPermutation(n);
  print_v(n);

  return 0;
}
