#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
    if (nums.size() > 1)
    {
        int slow = nums[0];
        int fast = nums[nums[0]];
        cout << slow << ", " << fast << endl;
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
            cout << slow << ", " << fast << endl;
        }
        fast = 0;
        cout << "-----"<<endl;
        while (fast != slow)
        {
            fast = nums[fast];
            slow = nums[slow];
            cout << slow << ", " << fast << endl;
        }
        return slow;
    }
    return -1;
    }
};

int main() {
  Solution s;
  
  vector<int> t = {3,2,3,4,5,3,6};
  cout << s.findDuplicate(t) << endl;

  return 0;
}
