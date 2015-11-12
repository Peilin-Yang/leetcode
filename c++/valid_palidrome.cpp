#include <iostream>
#include <cctype>
#include <vector>

using namespace std;

class Solution {
public:
    bool v(char c) {
        return (c>='0' && c<='9') || (c>='a' && c<='z') || (c>='A' && c<='Z'); 
    }
    bool isPalindrome(string s) {
        if (s.empty()) return true;
        int start = 0, end = s.size()-1;
        while(start < end) {
            while (!v(s[start]) && start < end) start++;
            if (start>=end) return true;
            while (!v(s[end]) && start < end) end--;
            if (start>=end) return true;
            char ss = tolower(s[start]);
            char ee = tolower(s[end]);
            cout << ss << " " << ee << endl;
            if (ss != ee) return false;
            start++;
            end--;
        }
        return true;
    }
};

int main() {
  Solution s;

  cout << boolalpha << s.isPalindrome("A man, a plan, a canal: Panama") << endl;
  cout << boolalpha << s.isPalindrome("race a car") << endl;

  return 0;
}
