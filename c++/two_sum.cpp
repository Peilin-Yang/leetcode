#include <map>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> results;
        map<int, int> m;
        for (int i = 0; i != numbers.size(); ++i){
            int offset = target - numbers[i];
            map<int, int>::iterator mit;
            mit = m.find(offset);
            if (mit != m.end()){
                results.push_back(mit->second);
                results.push_back(i+1);
                return results;
            }
            m.insert(pair<int, int>(numbers[i], i+1));
        }
    }
};


int main() {
    Solution *s = new Solution();
    int test[] = {1,-3,0,-41,5,36,3,50,13};
    vector<int> v(test, test + sizeof(test) / sizeof(int));
    vector<int> r = s->twoSum(v,9);
    for (vector<int>::iterator it=r.begin(); it!=r.end(); ++it)
    {
        cout<< *it << endl;
    }
    return 0;
}