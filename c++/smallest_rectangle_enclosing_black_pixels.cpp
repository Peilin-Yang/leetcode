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

void print_r(vector<vector<bool> >& r) {
  for (int i = 0; i != r.size(); i++) {
    for (int j = 0; j != r[i].size(); j++) {
      cout << r[i][j] << ",";
    }
    cout << endl;
  }
}

class Solution {
public:
int minArea(vector<vector<char>>& image, int x, int y) {
        if(image.empty()) return 0;
        int m = image.size(), n = image[0].size();
        int left = searchCol(image, 0, y, true);
        int right = searchCol(image, y+1, n, false);
        int top = searchRow(image, 0, x, true);
        int bottom = searchRow(image, x+1, m, false);
        return (right-left)*(bottom-top);
    }
    int searchCol(vector<vector<char>>& image, int low, int high, bool searchSmall) {
        int m = image.size();
        while (low < high) {
            int mid = low+(high-low)/2;
            int i = 0;
            for (; i < m; i++) {
                if (image[i][mid] == '1') break;
            }
            if (i == m) {
                if (searchSmall) low = mid+1;
                else high = mid;
            } else {
                if (searchSmall) high = mid;
                else low = mid+1;
            }
        }
        return low;
    }
    int searchRow(vector<vector<char>>& image, int low, int high, bool searchSmall) {
        int n = image[0].size();
        while (low < high) {
            int mid = low+(high-low)/2;
            int i = 0;
            for (; i < n; i++) {
                if (image[mid][i] == '1') break;
            }
            if (i == n) {
                if (searchSmall) low = mid+1;
                else high = mid;
            } else {
                if (searchSmall) high = mid;
                else low = mid+1;
            }
        }
        return low;
    }
};

int main() {
  Solution s;
  
  string a[] = {"0010", "0110", "0100"};
  vector<vector<char> > t;
  for (int i = 0; i < sizeof(a)/sizeof(string); i++) {
    vector<char> tmp;
    for (int j = 0; j < a[i].size(); j++) {
      tmp.push_back(a[i][j]);
    }
    t.push_back(tmp);
  }

  cout << s.minArea(t, 0, 2) << endl;

  return 0;
}
