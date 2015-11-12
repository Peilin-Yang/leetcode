#include <iostream>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        int r = 0;
        int i = 1;
        while ((i+1)*(i+1) <= n) i++;
        cout << "i:" << i << endl;
        int s = 0;
        while (i >= 1) {
            cout << "++++++++++++++++++" << endl;
            while (true) {
                s += i*i;
                cout << "i:" << i << " s:" << s << endl;
                if (s == n) return ++r;
                if (s < n) {
                    r++;
                }
                else {
                    s -= i*i;
                    break;
                }
            }
            i--;
        }
        return r;
    }
};

int main() {
  Solution s;
  cout << s.numSquares(12) << endl;

  return 0;
}
