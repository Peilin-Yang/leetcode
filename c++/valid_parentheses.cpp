#include<stack>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> tmp;
        for (int i = 0; i != s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                tmp.push(s[i]);
            }
            if (s[i] == ')') {
                if(tmp.empty() || tmp.top() != '(') return false;
                tmp.pop();
            }
            if (s[i] == '}') {
                if(tmp.empty() || tmp.top() != '{') return false;
                tmp.pop();
            }
            if (s[i] == ']') {
                if(tmp.empty() || tmp.top() != '[') return false;
                tmp.pop();
            }
        }
        
        return tmp.empty();
    }
};

int main() {
  Solution s;

  cout << s.isValid("()") << endl;
  cout << s.isValid("]") << endl;

  return 0;
}
