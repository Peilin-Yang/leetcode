#include<cstdlib>
#include<iostream>

using namespace std;
class Solution {
public:
    bool isValid(string ns) {
        // ns: number string
        if (ns.empty()) return false;
        int l = ns.size();
        int i = 0;
        if (ns[0] == '+' || ns[0] == '-') i = 1;
        int num_num = 0, num_point = 0;
        for (; i != l; i++) {
            if (ns[i] >= '0' && ns[i] <= '9') {
                num_num++;
            } else if (ns[i] == '.') {
                num_point++;
            } else {
                break;
            }
        }
        if (num_num < 1 || num_point > 1) return false;
        if (i < l) {
            if (ns[i] == 'e' || ns[i] == 'E') {
                if (i+1 < l && ns[i+1]=='+' || ns[i+1] == '-') i+=2;
                else i++;
                num_num = 0;
                while (i < l) {
                    if (ns[i] >= '0' && ns[i] <= '9') {
                        i++;
                        num_num++;
                    } else {
                        return false;
                    }
                }
                if (num_num < 1) return false;
            } else {
                return false;   
            }
        }
        return true;
    }
    bool isNumber(string s) {
        int l = s.size();
        int i = 0;
        while (i < l && s[i] == ' ') {
            i++;
	}
        if (i == l) return false;
        string target = "";
        while (i < l && s[i] != ' ') {
            target += s[i];
            i++;
        }
        while (i < l) {
            if (s[i] != ' ') return false;
            i++;
        }
        return isValid(target);
    }
};

int main() {
  Solution s;
  string str;
  
  /*
  str = ".1";
  cout << str << " --- " << std::boolalpha << s.isNumber(str) << endl;

  str = ".";
  cout << str << " --- " << std::boolalpha << s.isNumber(str) << endl;

  str = "0e";
  cout << str << " --- " << std::boolalpha << s.isNumber(str) << endl;
  
  str = "3";
  cout << str << " --- " << std::boolalpha << s.isNumber(str) << endl;
  */
  str = "2e0";
  cout << str << " --- " << std::boolalpha << s.isNumber(str) << endl;

  return 0;
}
