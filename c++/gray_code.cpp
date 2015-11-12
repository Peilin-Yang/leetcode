#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void print_v(vector<int>& v) {
  for (int i = 0; i != v.size(); i++) {
      cout << v[i] << ",";
  }
  cout << endl;
}

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> r;
        int cnt = pow(2, n);
        for (int i = 0; i < cnt; i++) {
            r.push_back((i>>1)^i);
        }
        return r;
    }
};

int main() {
  Solution s;
  
  vector<int> r;
  r = s.grayCode(3);
  print_v(r);

  return 0;
}
