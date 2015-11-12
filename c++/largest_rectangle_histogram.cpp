#include<vector>
#include<stack>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        height.push_back(0);
        int l = height.size(), a = 0;
        stack<int> s;
        for (int i = 0; i < l; i++) {
            while (!s.empty() && height[s.top()] > height[i]) {
                int h = height[s.top()];
                s.pop();
                int l = s.empty()?-1:s.top();
                a = max(a, h*(i-l-1));
            }
            s.push(i);
        }
        return a;
    }
};

int main() {
  Solution s;
  
  int a[] = {1};
  vector<int> n(a, a+sizeof(a)/sizeof(int));
  cout << s.largestRectangleArea(n) << endl;

  return 0;
}
