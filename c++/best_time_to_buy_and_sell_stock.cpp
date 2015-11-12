#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int ret = 0;
        int min_idx = 0;
        bool found = false;
        for (int i = 0; i != prices.size(); ++i) {
            int diff = prices[i] - prices[min_idx];
            if (diff < 0) {
                min_idx = i;
            }
            if (diff > ret) {
                ret = diff;
            }
        }
        return ret;
    }
};


int main() {
    Solution *s = new Solution();
    int a[] = {38,134,84,27,4956,283,238,1245,3,467,1233};
    vector<int> test (a, a+sizeof(a)/sizeof(int));
    int r = s->maxProfit(test);

    cout << r << endl;

    return 0;
}
