#include <map>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <climits>
using namespace std;

class Solution {
public:
    bool isSameSign(int i1, int i2) {
      return (i1<0&&i2<0 || i1>0&&i2>0) ? true : false;
    }
    /*
    int divide(int dividend, int divisor) {
      if(divisor == 1)
          return dividend;
      if(dividend == INT_MIN && abs(divisor) == 1)
          return INT_MAX;

      bool is_same_sign = isSameSign(dividend, divisor);
      long d1 = labs((long)dividend);
      long d2 = labs((long)divisor);
      long result = 0; 
      while (d1 >= d2) {
        int step = 0;
        long tmp = d2;
        while ((tmp << 1) < d1) {
          tmp = tmp << 1;
          step++;
        }
        result += (unsigned long)1 << step;
        d1 -= tmp;
        cout << d1 << endl;
      } 
      return is_same_sign?result:-result;
    }*/
    int divide(int dividend, int divisor) {
        if(divisor == 1) return dividend;
        if(dividend == INT_MIN && abs(divisor) == 1) return INT_MAX;
        bool neg = (dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0);
        long d1 = labs((long)dividend);
        long d2 = labs((long)divisor);
        long r = 0;
        while (d1 >= d2) {
            cout << "hhh" << endl;
            long tmp = d2;
            int step = 0;
            while ((tmp<<1) < d1) {
                tmp = tmp << 1;
                step++;
            }
            r += 1 << step;
            d1 -= tmp;
            cout << d1 << endl;
        }
        return neg?-r:r;
    }
};


int main() {
    Solution *s = new Solution();

    //cout<< "results: " << s->divide(50000, -3) << endl;
    //cout<< "results: " << s->divide(52343, 2) << endl;
    //cout<< "results: " << s->divide(-2147483648, 2) << endl;
    cout<< "results: " << s->divide(2147483647, 2) << endl;

    return 0;
}
