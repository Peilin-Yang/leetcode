#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    string t(int num) {
        assert(num<1000 && num >= 0);
        string mapping1[] = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        string mapping2[] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        string res("");
        int tens = num%100;
        if (tens < 20 && tens > 0) res = mapping1[tens-1];
        if (tens >= 20 && tens < 100) {
            if (tens%10 == 0) res = mapping2[tens/10-2];
            else res = mapping2[tens/10-2]+" "+mapping1[tens%10-1];
        }
        if (num >= 100) res = mapping1[num/100-1]+" Hundred "+res;
        return res;
    }
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        string s_mapping[] = {"Thousand", "Million", "Billion", "Trillion"};
        string res;
        int idx = -1;
        char *e;
        while (num > 0) {
            string tmp = t(num%1000);
            if (idx >= 0) {
                if (!tmp.empty()) {
                    if(!res.empty()) res = tmp+" "+s_mapping[idx]+" "+res;
                    else res = tmp+" "+s_mapping[idx];
                }
            } else res = tmp;
            idx++;
            num /= 1000;
        }
        return res;
    }
};

int main() {
  Solution s;
  
  cout << s.numberToWords(1000) << endl;
  cout << s.numberToWords(123) << endl;
  cout << s.numberToWords(12345) << endl;
  cout << s.numberToWords(1234567) << endl;
  cout << s.numberToWords(123000) << endl;
  cout << s.numberToWords(1000010) << endl;

  return 0;
}
