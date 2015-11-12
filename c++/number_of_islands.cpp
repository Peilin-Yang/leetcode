#include <iostream>
#include <vector>
#include <stack>

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
    void mark_visited(vector<vector<char> >& grid, int row, int col, vector<vector<bool> >& visited) {
        int m = grid.size();
        int n = grid[0].size();
        if (row < 0 || row >= m || col < 0 || col >= n) return;
        visited[row][col] = true;
        if (row-1 >= 0 && grid[row-1][col] == '1' && !visited[row-1][col]) mark_visited(grid, row-1, col, visited);
        if (col-1 >= 0 && grid[row][col-1] == '1' && !visited[row][col-1]) mark_visited(grid, row, col-1, visited);
        if (row+1 < m && grid[row+1][col] == '1' && !visited[row+1][col]) mark_visited(grid, row+1, col, visited);
        if (col+1 < n && grid[row][col+1] == '1' && !visited[row][col+1]) mark_visited(grid, row, col+1, visited);
    }
    int numIslands(vector<vector<char> >& grid) {
        if (grid.empty()) return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    mark_visited(grid, i, j, visited);
                    res++;
                }
            }
        }
        return res;
    }
};

int main() {
  Solution s;
  
  //vector<vector<char> > t = {{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};
  vector<vector<char> > t = {{'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'}};

  cout << s.numIslands(t) << endl;

  return 0;
}
