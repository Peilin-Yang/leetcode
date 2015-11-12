#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Solution {

public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int min_candies = n;

        int range = 0;
        for (size_t i = 0; i < n - 1; ) {
            int start = i;
            while (ratings[i] < ratings[i+1] && i < n-1) ++i;
            range = i - start;
            min_candies += (range * (range + 1)) / 2;
            if (i == n-1) break;

            start = i;
            while (ratings[i] > ratings[i+1] && i < n-1) ++i;
            int k = i - start - 1;
            cout << k << endl;
            min_candies += (k * (k + 1)) / 2;
            if (i - start > range) min_candies += (i - start - range);
            if (ratings[i] == ratings[i+1]) ++i;
        }
        return min_candies;
    }
};


int main() {
  Solution s;

  int a[] = {1,2,3,2,1,0,1,1};
  vector<int> r(a, a+sizeof(a)/sizeof(int));

  cout << s.candy(r) << endl;

  return 0;
}
