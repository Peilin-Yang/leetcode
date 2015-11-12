#include <iostream>
#include <vector>

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

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        if (matrix.empty()) return false;
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i != m; i++) {
cout << matrix[i][0] << " " << matrix[i][n-1] << endl;
            if (target >= matrix[i][0] && target <= matrix[i][n-1]) {
                int start = 0, end = n-1;
                while (start <= end) {
                    int mid = (start+end)/2;
                    if (target == matrix[i][mid]) return true;
                    if (target > matrix[i][mid]) start = mid+1;
                    else end = mid-1;
                }
            } else if (target < matrix[i][0]) {
                return false;
            }
        }
        return false;
    }
};

int main() {
  Solution s;

  int a1[] = {5};
  int a2[] = {6};
  vector<int> n1(a1,a1+sizeof(a1)/sizeof(int));
  vector<int> n2(a2,a2+sizeof(a2)/sizeof(int));

  vector<vector<int> > m;
  m.push_back(n1);
  m.push_back(n2);
  
  cout << std::boolalpha << s.searchMatrix(m, 6) << endl;

  return 0;
}
