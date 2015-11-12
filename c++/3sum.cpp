#include <map>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
      vector<vector<int> > r;
      if (num.size() < 3) return r;
      std::sort(num.begin(), num.end());
      for (size_t i = 0; i <= num.size()-3; i++) {
        if (i>0 && num[i] == num[i-1]) {
          cout << "already" << endl;
          continue;
        }
        int neg_i = -num[i];
        int start = i+1;
        int end = num.size()-1;
        while (start < end) {
          if ((num[start] + num[end]) > neg_i) {
            end--;
          } else if ((num[start] + num[end]) < neg_i) {
            start++;
          } else {
            int tmp_start = num[start];
            vector<int> tmp_r;
            tmp_r.push_back(num[i]);
            tmp_r.push_back(num[start]);
            tmp_r.push_back(num[end]);
            r.push_back(tmp_r);
            while (start < end && num[start] == tmp_start) {
              start++;
            }
            if (start >= end) {
              break;
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
  
  int myints[] = {7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};
  std::vector<int> a(myints, myints + sizeof(myints) / sizeof(int) );
  vector<vector<int> > r = s.threeSum(a);
  print_solution(r);

  return 0;
}
