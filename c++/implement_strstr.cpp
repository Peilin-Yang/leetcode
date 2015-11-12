#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        int cur_start = -1, next_start = -1;
        int l = haystack.size();
        int n = needle.size();
        for (int i = 0; i != l; ++i) {
            if (haystack[i] == needle[0]) {
                cur_start = i;
                bool found_next_start = false;
                bool found = true;
                for (int j = 0; j != n && cur_start != l; j++, cur_start++) {
                    if (haystack[cur_start] == needle[0] && !found_next_start) {
                        next_start = cur_start;
                        found_next_start = true;
                    } 
                    if (haystack[cur_start] != needle[j]) {
                        found = false;
                        break;
                    }
                }
                if (found) return i;
                if (found_next_start) i = next_start;
            }
        }
        return -1;
    }

};

int main() {
  Solution s;

  string a,b;
  a = "";
  b = "";
  cout << s.strStr(a, b) << endl;
  a = "misisissippi";
  b = "issi";
  cout << s.strStr(a, b) << endl;
  a = "mississippi";
  b = "pi";
  cout << s.strStr(a, b) << endl;
  return 0;
}
