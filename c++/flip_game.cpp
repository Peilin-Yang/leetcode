#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> r;
        if (s.empty()) return r;
        for (int i = 0; i < s.size()-1; i++) {
            cout << "111" << endl;
            if (s[i] == '+' && s[i+1] == '+') r.push_back(s.substr(0,i)+"--"+s.substr(i+2));
        }
        return r;
    }
};

int main() {
  Solution s;
  
  s.generatePossibleNextMoves("");

  return 0;
}
