#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n%2!=0) return false;
        while (n>1) {
            long long tmp = 2;
            while ((tmp*tmp) < n) {
                tmp*=tmp;
                cout << tmp << endl;
            }
            cout << n << "," <<tmp << endl;
            if (n%tmp) return false;
            n/=tmp;
        }
        return true;
    }
};

int main() {
  Solution s;
  
  cout << boolalpha << "131072: " << s.isPowerOfTwo(131072) << endl;

  return 0;
}
