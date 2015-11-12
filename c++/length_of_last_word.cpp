#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int l = s.size();
        int last_space = l-1;
        while (last_space>=0) {
            if (s[last_space] == ' ') break;
            last_space--;
        }
        if (last_space < 0) return l;
        return l-last_space-1;
    }
};

int main() {
  Solution s;
  cout << s.lengthOfLastWord(" ") << endl;
}

