#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    long long c(int n) {
        long long r = 0;
        while (n) {
            int tmp = n%10;
            r += tmp*tmp;
            n/=10;
        }
        cout << "r:" << r << endl;
        return r;
    }
    bool isHappy(int n) {
        unordered_set<long long> m;
        long long nn = n;
        while (1) {
            cout << nn << endl;
            if (nn == 1) return true;
            if (m.find(nn) != m.end()) return false;
            m.insert(nn);
            nn = c(nn);
        }
    }
};

int main() {
  Solution s;
  
  cout << boolalpha << "7: " << s.isHappy(7) << endl;

  return 0;
}
