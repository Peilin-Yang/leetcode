#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_r(vector<string>& r) {
  for (int i = 0; i != r.size(); i++) 
      cout << r[i] << ",";
    cout << endl;
}

class Solution {
public:
    static bool comp(string s1, string s2) {
        return s1+s2 > s2+s1;
    }

    string largestNumber(vector<int>& nums) {
        vector<string> n;
        string r("");
        int l = nums.size();
        for (int i = 0; i < l; i++) {
            n.push_back(std::to_string(nums[i]));
        }
        std::sort(n.begin(), n.end(), Solution::comp);
        print_r(n);
        for (int i = 0; i < l; i++) {
            r += n[i];
        }
        int found = r.find_first_not_of('0');
        if (found != string::npos) return r.substr(found, r.size()-found);
        return "0";
    }
};

int main() {
  Solution s;
  
  //vector<int> t = {3, 30, 34, 5, 9};
  vector<int> t = {0, 0};

  cout << s.largestNumber(t) << endl;

  return 0;
}
