#include <vector>
#include <iostream>
using namespace std;

void p(vector<int>& v) {
  for (int i = 0; i < v.size(); i++) cout << v[i] << ",";
  cout << endl;
}

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size(), h = 0;
        vector<int> counts(n+1, 0);
        for (int i = 0; i < n; i++) 
            counts[min(citations[i], n)]++;
        p(counts);
        for (int i = n; i; i--) {
            h += counts[i];
            if (h >= i) return i;
        }  
        return h;
    }
};


int main() {
    Solution *s = new Solution();
    //int test[] = {3,1,2,4,5};
    //int test[] = {1,4,4,4,4,4,4};
    int test[] = {0,1,5,5,6};
    vector<int> v(test, test + sizeof(test) / sizeof(int));
    cout << s->hIndex(v) << endl;
    return 0;
}
