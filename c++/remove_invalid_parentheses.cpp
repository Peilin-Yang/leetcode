#include <vector>
#include <queue>
#include <unordered_set>
#include <iostream>

using namespace std;

void p(vector<string>& v) {
  for (int i = 0; i < v.size(); i++) cout << v[i] << ",";
  cout << endl;
}

class Solution {
public:
    bool isValid(string s) {
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') cnt++;
            if (s[i] == ')') {
                cnt--;
                if (cnt < 0) return false;
            }
        }
        return cnt == 0;
    }
    vector<string> removeInvalidParentheses(string s) {
        int n = s.size();
        vector<string> res;
        queue<string> q;
        unordered_set<string> m;
        q.push(s);
        bool found = false;
        while (!q.empty()) {
            string cur = q.front();
            q.pop();
            if (isValid(cur)) {
                found = true;
                res.push_back(cur);
            }
            if (found) continue;
            for (int i = 0; i < cur.size(); i++) {
                if (cur[i] != '(' && cur[i] != ')') continue;
                string tmp = cur.substr(0, i)+cur.substr(i+1);
                if (m.find(tmp) == m.end()) {
                    m.insert(tmp);
                    q.push(tmp);
                }
            }
        }
        return res;
    }
};



int main() {
    Solution *s = new Solution();
    vector<string> r;
    r = s->removeInvalidParentheses("()())()");
    p(r);
    return 0;
}
