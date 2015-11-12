#include <vector>
#include <iostream>

using namespace std;

void print_v(vector<string> & v) {
  for (int i = 0; i != v.size(); i++) {
    cout << v[i] << ",";
  }
  cout << endl;
}


void print_r(vector<vector<int> >& r) {
  for (int i = 0; i != r.size(); i++) {
    for (int j = 0; j != r[i].size(); j++) {
      cout << r[i][j] << ",";
    }
    cout << endl;
  }
}


class Solution {
public:
    string getPermutation(int n, int k) {
        vector<string> nums(n);
        int pCnt = 1;
        string r;
        for (int i = 0; i != n; i++) {
            nums[i] = to_string(i+1);
            pCnt *= i+1;
        }
        k--;
        for (int i = 0; i < n; i++) {
            pCnt /= n-i;
            int choosed = k/pCnt;
            r += nums[choosed];
            for (int j = choosed; j < n-i && j < n-1; j++) {
                nums[j] = nums[j+1];
            }
            k %= pCnt;
        }
        return r;
    }
};


int main() {
  Solution s;

  string r = s.getPermutation(3, 5);
  cout << r << endl;
  return 0;
}
