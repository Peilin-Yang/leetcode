#include<iostream>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int l1 = num1.size(), l2 = num2.size();
        string r(l1+l2, '0');
        for (int i = l1-1; i >= 0; i--) {
            int carry = 0;
            int this_i = num1[i]-'0';
            int j = l2-1;
            for (j = l2-1; j >= 0; j--) {
                int this_j = num2[j]-'0';
                int this_p = this_i * this_j + carry;
                int this_digit = this_p % 10;
                int exist = r[i+j+1]-'0';
                int this_total = this_digit + exist;
                r[i+j+1] = this_total % 10 + '0';
                carry = this_p/10+this_total/10;
            }
            if (carry > 0) {
                r[i+j+1] = carry+'0';
            }
        }
        
        if (r.find_first_not_of('0') != string::npos) {
            int start = r.find_first_not_of('0');
            int s = r.size();
            return r.substr(start, s-start);
        }
        return "0";
    }
};

int main() {
  Solution s;

  cout << s.multiply(string("04"), string("009")) << endl;
  cout << s.multiply(string("9"), string("9")) << endl;

  return 0;
}
