#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void print_solution(vector<vector<char> >& flags) {
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
    void check(vector<vector<char> >& board, int row, int col) {
        if (row < 0 || col < 0 || row > board.size()-1 || col > board[0].size()-1 || board[row][col] != 'O') {
            return;
        }
        board[row][col] = '1';
        check(board, row-1, col);
        check(board, row+1, col);
        check(board, row, col-1);
        check(board, row, col+1);
    }
    void solve(vector<vector<char> >& board) {
        if (board.empty()) return;
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            check(board, i, 0);
            check(board, i, n-1);
        }
        for (int i = 0; i < n; i++) {
            check(board, 0, i);
            check(board, m-1, i);
        }
        print_solution(board);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '1') board[i][j] = 'O';
                else if (board[i][j] == 'O') board[i][j] = 'X';
            }
        } 
    }
};

int main() {
  Solution s;
  
  //string a[] = {"XXXX", "XOOX", "XXOX", "XOXX"};
  string a[] = {"OO", "OO"};
  vector<vector<char> > t;
  for (int i = 0; i < sizeof(a)/sizeof(string); i++) {
    vector<char> tmp;
    for (int j = 0; j < a[i].size(); j++) {
      tmp.push_back(a[i][j]);
    }
    t.push_back(tmp);
  }

  s.solve(t);
  print_solution(t);

  return 0;
}
