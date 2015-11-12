#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int l = numbers.size();
        for (int i = 0; i < l; i++) {
            if (numbers[i] >= target) break;
            cout << i << endl;
            vector<int> res(1, i+1);
            int s = i+1, e = l-1;
            while (s<=e) {
                int mid = s+(e-s)/2;
                if (numbers[mid] + numbers[i] == target) {
                    res.push_back(mid+1);
                    return res;
                } 
                if (numbers[mid]+numbers[i] > target) e = mid-1;
                else s = mid+1;
            }
        }
    }
};


int main() {
    Solution *s = new Solution();
    //int test[] = {1,-3,0,-41,5,36,3,50,13};
    int test[] = {-3,3,4,90};
    vector<int> v(test, test + sizeof(test) / sizeof(int));
    vector<int> r = s->twoSum(v, 0);
    for (vector<int>::iterator it=r.begin(); it!=r.end(); ++it)
    {
        cout<< *it << ",";
    }
    cout << endl;
    return 0;
}
