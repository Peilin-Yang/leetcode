#include <iostream>
#include <cstdio>
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
    bool e(vector<vector<char> >& board, string word, int row, int col, string r, int r_start) {
        //cout << "row:" << row << " col:" << col << " r:" << r << " r_start:" << r_start << endl;
        if (r == word) return true;
        if (row >= board.size() || row < 0 || col < 0 || col >= board[0].size() || board[row][col] != word[r_start]  || board[row][col] == '\0') {
            return false;
        }

        char c = board[row][col];
        r += c;
        r_start++;
        board[row][col] = '\0';
        if (e(board, word, row+1, col, r, r_start) || e(board, word, row-1, col, r, r_start) || e(board, word, row, col-1, r, r_start) || e(board, word, row, col+1, r, r_start)) return true;
        
        board[row][col] = c;
        return false;
    }
    bool exist(vector<vector<char> >& board, string word) {
        if (board.empty()) return false;
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i != m; i++) {
            for (int j = 0; j != n; j++) {
                string tmp;
                if (e(board, word, i, j, tmp, 0)) return true;
            }
        }
        return false;
    }
};

int main() {
  Solution s;
  /*  
  vector<char> v1;
  v1.push_back('A');
  v1.push_back('B');
  v1.push_back('C');
  v1.push_back('D');
  v1.push_back('E');
  vector<char> v2;
  v2.push_back('T');
  v2.push_back('S');
  v2.push_back('R');
  v2.push_back('Q');
  v2.push_back('F');
  vector<char> v3;
  v3.push_back('M');
  v3.push_back('N');
  v3.push_back('O');
  v3.push_back('P');
  v3.push_back('G');
  vector<char> v4;
  v4.push_back('L');
  v4.push_back('K');
  v4.push_back('J');
  v4.push_back('I');
  v4.push_back('H');
  */
  /*
  vector<char> v1;
  v1.push_back('A');
  v1.push_back('B');
  v1.push_back('C');
  v1.push_back('E');
  vector<char> v2;
  v2.push_back('S');
  v2.push_back('F');
  v2.push_back('C');
  v2.push_back('S');
  vector<char> v3;
  v3.push_back('A');
  v3.push_back('D');
  v3.push_back('E');
  v3.push_back('E');
  */
  vector<char> v1;
  v1.push_back('C');
  v1.push_back('A');
  v1.push_back('A');
  vector<char> v2;
  v2.push_back('A');
  v2.push_back('A');
  v2.push_back('A');
  vector<char> v3;
  v3.push_back('B');
  v3.push_back('C');
  v3.push_back('D');
  
  vector<vector<char> > v;
  v.push_back(v1);
  v.push_back(v2);
  v.push_back(v3);
  //v.push_back(v4);
  //string t("ABCCED");
  //string t("ABCB");
 
  //string t("ABCDEFGHIJKLMNOPQRST");
  string t("AAB");
  cout << std::boolalpha << s.exist(v, t) << endl;

  return 0;
}
