#include <iostream>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

void print_solution(vector<vector<int> >& flags) {
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
    void helper(vector<vector<int> >& rooms, int row, int col, int val) {
        queue<pair<int, int> > q;
        q.push(make_pair(row, col));
        while (!q.empty()) {
            int s = q.size();
            for (int k = 0; k<s; k++) {
                pair<int, int> t = q.front();
                q.pop();
                int i = t.first, j = t.second;
                rooms[i][j] = min(rooms[i][j], val);
                if (i > 0 && rooms[i-1][j]>val+1) q.push(make_pair(i-1, j));
                if (j > 0 && rooms[i][j-1]>val+1) q.push(make_pair(i, j-1));
                if (i < rooms.size()-1 && rooms[i+1][j]>val+1) q.push(make_pair(i+1, j));
                if (j < rooms[i].size()-1 && rooms[i][j+1]>val+1) q.push(make_pair(i, j+1));
            }
            val++;
        }
    }
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (rooms.empty()) return;
        int m = rooms.size(), n = rooms[0].size();
        for (int i = 0; i < rooms.size(); i++) {
            for (int j = 0; j < rooms[i].size(); j++) {
                if (rooms[i][j] == 0) {
                    helper(rooms, i, j, 0);
                }
            }
        }
    }
};

int main() {
  Solution s;
  
  vector<vector<int> > t = {{INT_MAX,-1,0,INT_MAX},{INT_MAX,INT_MAX,INT_MAX,-1},{INT_MAX,-1,INT_MAX,-1},{0,-1,INT_MAX,INT_MAX}};

  s.wallsAndGates(t);
  print_solution(t);

  return 0;
}
