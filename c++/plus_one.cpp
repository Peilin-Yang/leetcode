#include <vector>
#include <iostream>
using namespace std;

void p(vector<int>& v) {
  for (int i = 0; i < v.size(); i++) cout << v[i] << ",";
  cout << endl;
}

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits.empty()) return digits;
        int l = digits.size();
        int carry = 1;
        for (int i = l-1; i >=0; i--) {
            int r = digits[i] + carry;
            digits[i] = r%10;
            carry = r/10;
            cout << "r:" << r << " carry:" << carry << endl;
            if (carry == 0) break;
        }
        if (carry > 0) digits.insert(digits.begin(), carry);
        return digits;
    }
};


int main() {
    Solution *s = new Solution();
    int test[] = {8,9,4,5,0,0,7,9};
    vector<int> v(test, test + sizeof(test) / sizeof(int));
    vector<int> r; 
    r = s->plusOne(v);
    p(r);
    return 0;
}
