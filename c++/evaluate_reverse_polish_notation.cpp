#include <stack>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

void print_v(vector<string>& v) {
  for (int i = 0; i != v.size(); i++) cout << v[i] << ",";
  cout << endl;
}

class Solution {
public:
    int calculate(string s) {
        stack<char> q;
        int res;
        int l = s.size();
        for (int i = 0; i < l; i++) {
            if (s[i] == '+' || s[i] == '-' || (s[i]>='0' && s[i]<='9')) {
                q.push(s[i]);
            }
            else if (s[i] == '*' || s[i] == '/') {
                int ind = s[i] == '*' ? 0 : 1;
                int op1 = 0;
                int idx = 0;
                while(!q.empty() && q.top() >= '0' && q.top() <= '9') {
                    op1 += (q.top()-'0')*pow(10, idx);
                    idx++;
                    q.pop();
                }
                i++;
                int op2 = 0;
                while (i < l && s[i]>='0' && s[i]<='9') {
                    op2 = op2*10+(s[i]-'0');
                    i++;
                } 
                if (ind == 0) res = op1*op2;
                else res = op1/op2;
                while (res) {
                    q.push(res%10+'0');
                    res/=10;
                }
            }
        }
        
        return res;
    }
};

int main() {
  Solution s;
  
  string t = "3+23*56 ";
  cout << s.calculate(t) << endl;

  return 0;
}
