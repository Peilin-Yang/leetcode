#include <map>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &nums, int target) {
      vector<vector<int> > r;
      int l = nums.size();
      if (l < 4) return r;
      std::sort(nums.begin(), nums.end());
      for (size_t i = 0; i <= l-4; i++) {
        if (i>0 && nums[i] == nums[i-1]) {
          //cout << "already" << endl;
          continue;
        }
        for (size_t j = i+1; j <= l-3; j++) {
          if (j>i+1 && nums[j] == nums[j-1]) {
            //cout << "already" << endl;
            continue;
          }
          int neg = target-nums[i]-nums[j];
          cout << nums[i] << "," << nums[j] << "," << neg << endl;
          int start = j+1;
          int end = l-1;
          while (start < end) {
            if ((nums[start] + nums[end]) > neg) {
              end--;
            } else if ((nums[start] + nums[end]) < neg) {
              start++;
            } else {
              int tmp_start = nums[start];
              int tmp_end = nums[end];
              vector<int> tmp_r;
              tmp_r.push_back(nums[i]);
              tmp_r.push_back(nums[j]);
              tmp_r.push_back(nums[start]);
              tmp_r.push_back(nums[end]);
              r.push_back(tmp_r);
              while (start < end && nums[start] == tmp_start) {
                start++;
              }
              if (start >= end) {
                break;
              }
            }
          }
        }
      }

      return r;
    }
};


void print_solution(vector<vector<int> > &r) {
  cout << "---------------------------" << endl;
  for (size_t i = 0; i != r.size(); i++) {
    for (size_t j = 0; j != r[i].size(); j++) {
      cout << r[i][j] << ", ";
    }  
    cout << endl;
  } 
  cout << "---------------------------" << endl;

}


int main() {
  Solution s;
  
  //int myints[] = {7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};
  //int myints[] = {0,0,0,0};  //target 0
  int myints[] = {-1,0,1,2,-1,-4}; // target -1
  std::vector<int> a(myints, myints + sizeof(myints) / sizeof(int) );
  vector<vector<int> > r = s.fourSum(a, -1);
  print_solution(r);

  return 0;
}
