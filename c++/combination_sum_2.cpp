#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    std::vector<std::vector<int> > combinationSum(std::vector<int> &candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        std::vector<std::vector<int> > res;
        std::vector<int> combination;
        combinationSum(candidates, target, res, combination, 0);
        return res;
    }
private:
    void combinationSum(std::vector<int> &candidates, int target, std::vector<std::vector<int> > &res, std::vector<int> &combination, int begin) {
        if  (!target) {
            res.push_back(combination);
            return;
        }
        for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i) {
          if (i == begin || candidates[i] != candidates[i - 1]) {
            combination.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], res, combination, i+1);
            combination.pop_back();
          }
        }
    }
};

void print_solution(vector<vector<int> >& r) {
  for (int i = 0; i != r.size(); i++) {
    for (int j = 0; j != r[i].size(); j++) {
      cout << r[i][j] << ",";
    }
    cout << endl;
  }
  cout << endl;
}

int main() {
  Solution s;

  //int a[] = {2,3,6,7};
  //int a[] = {1};
  int a[] = {1,2};
  vector<int> n(a, a+sizeof(a)/sizeof(int));
  //int target = 7;
  //int target = 2;
  int target = 3;
  vector<vector<int> > r = s.combinationSum(n, target);
  print_solution(r);

  return 0;
}
