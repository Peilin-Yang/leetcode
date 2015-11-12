#include <stack>
#include <iostream>
#include <algorithm> 
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
      int result = 0;
      int left = -1;
      std::stack<int> r;
      for (int i = 0; i < s.size(); ++i) {
        if(s[i] == '(') r.push(i);            
        else {
          if (r.empty()) left=i;
          else {
            r.pop();
            if(r.empty()) result = std::max(result, i-left);
            else result = std::max(result, i-r.top());
          }
        }
      }
      return result;
    }
};
int main() {
    Solution *s = new Solution();
    cout<< "results: " << s->longestValidParentheses("(()") << endl;
    cout << "------------------------" << endl;
    cout<< "results: " << s->longestValidParentheses(")()())") << endl;
    cout << "------------------------" << endl;
    cout<< "results: " << s->longestValidParentheses("()(())") << endl;
    cout << "------------------------" << endl;
    cout<< "results: " << s->longestValidParentheses("()(()") << endl;
    cout << "------------------------" << endl;
    cout<< "results: " << s->longestValidParentheses("(()()") << endl;
    cout << "------------------------" << endl;
    cout<< "results: " << s->longestValidParentheses("(()())") << endl;

    return 0;
}

