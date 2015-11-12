#include <sstream>
#include <iostream>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        istringstream in("+"+s+"+");
        long long total = 0, tmp = 0, n;
        char op;
        while (in >> op) {
            if (op == '+' || op == '-') {
                total += tmp;
                in >> tmp;
                tmp *= op == '+'?1:-1;
            } else {
                in >> n;
                if (op == '*') tmp *= n;
                else tmp/=n;
            }
        }
        return total;
    }
};

int main() {
  Solution s;
  
  string t;
  t = "3+23*56 / 2 / 3-76";
  cout << t << "===" << s.calculate(t) << endl;
  t = "1-1+1";
  cout << t << "===" << s.calculate(t) << endl;
  t = "0-2147483647";
  cout << t << "===" << s.calculate(t) << endl;

  return 0;
}
