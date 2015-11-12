#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_r(vector<int>& r) {
  for (int i = 0; i != r.size(); i++) 
      cout << r[i] << ",";
    cout << endl;
}

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            x ^= nums[i];
        }
        return x;
    }
};

int main() {
  Solution s;
  
  //vector<int> t = {1,2,3,3,1,2,5,2,3,1};
  vector<int> t = {1,2,3,5,2,3,1};
  cout << s.singleNumber(t) << endl;;

  return 0;
}
