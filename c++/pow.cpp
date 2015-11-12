#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
      double ret = 1;
      if (n == 0) return 1;
      bool n_neg = n > 0 ? false : true;
      n = abs(n);
      double cur = x;
      while (n>0) {
        if(n%2 == 0) {
          cur *= cur;
          n /= 2;
        } else {
          ret *= cur;
          n--;
        }
      }
      return n_neg?1.0/ret:ret;
    }
};

int main() {
  Solution s;
  cout << s.myPow(8.88023, 3) << endl;
  return 0;
}
