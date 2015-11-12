#include <sstream>
#include <vector>
#include <iostream>

using namespace std;

void p(vector<string>& r) {
  for(int i = 0; i < r.size(); i++) cout << r[i] << ",";
  cout << endl;
}

class Solution {
public:
    int c(string s) {
        istringstream in('+'+s+'+');
        long long total = 0, tmp = 0, n;
        char op;
        while (in >> op) {
            if (op == '+' || op == '-') {
                total += tmp;
                in >> tmp;
                tmp *= op=='+'?1:-1;
            } else {
                in >> n;
                tmp *= n;
            }
        }
        return total;
    }
    string add_op(string s) {
        if (s.empty()) return "";
        int l = s.size();
        if (l == 1) {
            return s;
        } else {
            for(int i = 0; i < s.size()-1; i++) {
                //cout << add_op(s.substr(0, i+1)) + "+" + add_op(s.substr(i+1)) << endl;
                //cout << add_op(s.substr(0, i+1)) + "-" + add_op(s.substr(i+1)) << endl;
                //cout << add_op(s.substr(0, i+1)) + "*" + add_op(s.substr(i+1)) << endl;
                return add_op(s.substr(0, i+1)) + "*" + add_op(s.substr(i+1)); 
            }
        }
    }
    void h(string s, int target, vector<string>& res) {
        
    }
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        add_op(num);
        return res;
    }
};

int main() {
  Solution s;
  
  string t;
  int target;
  vector<string> r;

  t = "123";
  target = 6;
  r = s.addOperators(t, target);

  p(r);

  return 0;
}
