#include<vector>
#include<sstream>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<string> split(string s, bool ignore_empty = true, char delimeter=',') {
        stringstream ss(s);
        string tmp;
        vector<string> res;
        while (getline(ss, tmp, delimeter)) {
            if (ignore_empty && tmp.empty()) continue;
            res.push_back(tmp);
        }
        return res;
    }
    string csv_parser(string s) {
        vector<string> c1 = split(s, true, '"');
        string res;
        for (int i = 0; i < c1.size(); i++) {
            if (i % 2 == 0) {
                vector<string> c2 = split(c1[i]);
                for (int j = 0; j < c2.size(); j++) {
                    res += c2[j]+"|";
                }
            } else {
                res += c1[i]+"|";
            }
        }
        return res.empty()?res:res.substr(0, res.size()-1);
    }
};

int main() {
  Solution s;

  string t("\"\",\"a,b,c\",m,sdf,vb,\"au,djv,\",zz");
  cout << t << endl << s.csv_parser(t) << endl;
  return 0;
}
