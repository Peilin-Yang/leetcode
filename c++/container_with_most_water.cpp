#include <iostream>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        if (height.size() < 2) {
            return 0;
        }
        int m = INT_MIN;
        int start = 0;
        int end = height.size()-1;
        while (start < end) {
            int tmp = min(height[start], height[end])*(end-start);
            m = max(m, tmp);
            if (height[start] <= height[end]){
                start++;
            } else {
                end--;
            }
        }

        return m;
    }
};

int main() {
    Solution *s = new Solution();
    int a[] = {0.5, 19, 2.4, 30, 8.9};
    vector<int> test(a, a+sizeof(a)/sizeof(int));
    int r;

    r = s->maxArea(test);
    cout << r << endl;

    return 0;
}

