#include <vector>
#include <iostream>
using namespace std;

void p(vector<string>& v) {
  for (int i = 0; i < v.size(); i++) cout << v[i] << ",";
  cout << endl;
}

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        if (nums.empty()) {
            res.push_back(to_string(lower)+"->"+to_string(upper));
            return res; 
        }
        if (nums[0] != lower) nums.insert(nums.begin(), lower-1);
        if (nums[nums.size()-1] != upper) nums.push_back(upper+1);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - nums[i-1] == 2) res.push_back(to_string(nums[i-1]+1));
            if (nums[i] - nums[i-1] > 2) res.push_back(to_string(nums[i-1]+1)+"->"+to_string(nums[i]-1));
        }
        return res;
    }
};


int main() {
    Solution *s = new Solution();
    int test[] = {3,50,75};
    vector<int> v(test, test + sizeof(test) / sizeof(int));
    vector<string> r = s->findMissingRanges(v, 0, 99);
    p(r);
    return 0;
}
