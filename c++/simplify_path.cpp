#include<cstdlib>
#include<iostream>

using namespace std;
class Solution {
public:
    string simplifyPath(string path) {
    }
};

int main() {
  Solution s;
  string str;
  
  str = "/../";
  cout << str << " --- " << s.simplifyPath(str) << endl;

  return 0;
}
