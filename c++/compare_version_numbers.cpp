#include <iostream>
#include <sstream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream s1(version1), s2(version2);
        string t1, t2;
        long i1, i2;
        char *e;
        while (getline(s1, t1, '.')) {
            if (!getline(s2, t2, '.')) {
                i1 = strtol(t1.c_str(), &e, 10);
                if (i1 != 0) return 1;
                continue;
            }
            i1 = strtol(t1.c_str(), &e, 10);
            i2 = strtol(t2.c_str(), &e, 10);
            //cout << "i1:" << i1 << " i2:" << i2 << endl;
            if (i1 > i2) return 1;
            if (i1 < i2) return -1;
        }
        while (getline(s2, t2, '.')) {
            i2 = strtol(t2.c_str(), &e, 10);
            if (i2 != 0) return -1;
        }
        return 0;
    }
};


int main() {
  Solution s;

  cout << s.compareVersion("1.1", "1") << endl;
  cout << s.compareVersion("1", "1.1") << endl;

  return 0;
}
