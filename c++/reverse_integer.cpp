#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long r = 0;
        bool neg = x < 0 ? true : false;
        int tmp = neg ? -x : x;
        while (tmp != 0) {
            r = r*10 + tmp%10;
            tmp /= 10;
        }
        if (r > INT_MAX || r < INT_MIN) r = 0;
        return neg?-r:r;
    }
};

int main() {
    Solution *s = new Solution();
    int test = 1000000003;
    int r;

    cout << 0x7fffffff << endl;
    cout << INT_MAX << endl;
  
    r = s->reverse(test);
    cout << test << ":" << r << endl;

    test = -23468365;
    r = s->reverse(test);
    cout << test << ":" << r << endl;

    test = -100000000;
    r = s->reverse(test);
    cout << test << ":" << r << endl;
    
    test = 1534236469;
    r = s->reverse(test);
    cout << test << ":" << r << endl;

    test = -2147483648;
    r = s->reverse(test);
    cout << test << ":" << r << endl;

    test = 100;
    r = s->reverse(test);
    cout << test << ":" << r << endl;
    return 0;
}
