#include <stack>
#include <queue>
#include <deque>
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
    int atom(string s) {
        int res = 0;
        queue<int> q;
        for (int i = 0; i < s.size();) {
            if (s[i] == '+' || s[i] == '-') {
                int ind = s[i]=='+'?0:1;
                int cur = q.front();
                q.pop();
                i++;
                int tmp = 0;
                while (i < s.size() && s[i]!='+' && s[i]!='-') {
                    if (s[i] == ' ') {i++; continue;}
                    tmp = tmp*10+(s[i]-'0');
                    i++;
                }
                if (ind == 0) res = cur+tmp;
                else res = cur-tmp;
                q.push(res);
            } else  {
                int tmp = 0;
                while (i < s.size() && s[i]!='+' && s[i]!='-') {
                    if (s[i] == ' ') {i++; continue;}
                    tmp = tmp*10+(s[i]-'0');
                    i++;
                }
                q.push(tmp);
            }
        }
        return q.front();
    }
    int calculate(string s) {
        return atom(s);
    }
};

int main() {
  Solution s;
  
  string t;
  t = "3+23-78-   76+ 123";
  cout << t << "=" << s.calculate(t) << endl;
  //t = "1-1+1";
  //cout << t << "=" << s.calculate(t) << endl;
  //t = "0-2147483647";
  //cout << t << "=" << s.calculate(t) << endl;

  return 0;
}
