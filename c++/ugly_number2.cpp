#include <iostream>
#include <cctype>
#include <vector>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        if (n == 1) return 1;
        int i2 = 0, i3 = 0, i5 = 0;
        vector<int> k(n);
        k[0] = 1;
        for (int i = 1; i < n; i++) {
            k[i] = min(k[i2]*2, min(k[i3]*3, k[i5]*5));
            if (k[i] == k[i2]*2) i2++;
            if (k[i] == k[i3]*3) i3++;
            if (k[i] == k[i5]*5) i5++;
        }
        for (int i = 0; i < n; i++) cout << k[i] << ",";
        cout << endl;
        return k[n-1];
    }
};

int main() {
  Solution s;

  cout << s.nthUglyNumber(11) << endl;

  return 0;
}
