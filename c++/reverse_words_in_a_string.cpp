#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        int l = s.size();
        if (s.find_first_not_of(' ') != string::npos) s=s.substr(s.find_first_not_of(' '));
        if (s.find_last_not_of(' ') != string::npos) s=s.substr(0, s.find_last_not_of(' ')+1);
cout << s << endl;
        reverse(s.begin(), s.end());
cout << s << endl;
        int start = 0, len = 0;
        for (int i = 0; i < l; i++) {
            if (s[i] == ' ') {
cout << "start:" << start << " len:" << len << endl;
                reverse(s.begin()+start, s.begin()+start+len);
                while (i < l && s[i] == ' ') i++;
                start = i;
                len = 1;
            } else {
                len++;
            }
        }
        if (start < l) reverse(s.begin()+start, s.begin()+start+len);
    }
};


int main() {
  Solution s;

  string r("  the sky   is  blue   ");
  s.reverseWords(r);
  cout << r << endl;
  return 0;
}
