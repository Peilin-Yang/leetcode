#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void print_solution(vector<vector<bool> >& flags) {
  //cout << "i:" << flags.size() << endl;
  for(int i = 0; i != flags.size(); i++) {
    //cout << "j:" << flags[i].size() << endl;
    for(int j = 0; j != flags[i].size(); j++) {
      cout << flags[i][j] << ",";
    }
    cout << endl;
  }
}

void print_r(vector<vector<bool> >& r) {
  for (int i = 0; i != r.size(); i++) {
    for (int j = 0; j != r[i].size(); j++) {
      cout << r[i][j] << ",";
    }
    cout << endl;
  }
}

class Solution {
public:
    int maximalRectangle(vector<vector<char> >& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> h(n+1, 0);
        int res = 0;
        for (int i = 0; i < m; i++) {
            stack<int> s;
            for (int j = 0; j < n+1; j++) {
                if (j < n) h[j] = matrix[i][j] == '1' ? h[j]+1 : 0;
                while (!s.empty() && h[s.top()]>h[j]) {
                    cout << "111" << endl;
                    int height = h[s.top()];
                    s.pop();
                    int l = s.empty() ? -1 : s.top();
                    cout << "height:" << height << " l:" << l << endl;
                    res = max(res, height*(j-l-1));
                }
                s.push(j);
            }
        }
        return res;
    }
};

int main() {
  Solution s;
  
  vector<vector<char> > t;
  vector<char> t1;
  t1.push_back('1');
  t.push_back(t1);

  cout << s.maximalRectangle(t) << endl;

  return 0;
}
