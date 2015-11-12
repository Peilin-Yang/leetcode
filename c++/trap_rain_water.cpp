#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int summap = 0;
        int sumtot = 0;
        int l = height.size();
        
        for(int i = 0; i < l; i++) summap += height[i];

        int left = 0, right = l - 1;
        int leftbar = 0, rightbar = 0;
        while(left <= right) {
            leftbar = max(height[left], leftbar);
            rightbar = max(height[right], rightbar);
            cout << "leftbar:" << leftbar << " rightbar:" << rightbar << endl;
            if(leftbar <= rightbar) {
                sumtot += leftbar;
                left++;
            } else {
                sumtot += rightbar;
                right--;
            }
        }
        return sumtot - summap;
    }
};

int main() {
  Solution s;

  //int a[] = {0,1,0,2,1,0,1,3,2,1,2,1};
  //int a[] = {5,2,1,2,1,5};
  int a[] = {4,2,3};
  vector<int> n(a, a+sizeof(a)/sizeof(int));

  cout << s.trap(n) << endl;
}
