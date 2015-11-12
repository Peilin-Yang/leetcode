#include <vector>
#include <iostream>

using namespace std;

void print_v(vector<string>& v) {
  for (int i = 0; i != v.size(); i++) cout << v[i] << ",";
  cout << endl;
}

class Solution {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res("");
        int l = strs.size();
        for (int i = 0; i < l; i++) {
            res += to_string(strs[i].size())+"#"+strs[i];
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        int n = s.size();
        int cur = 0, cur_start = 0;
        while (cur < n) {
            if (s[cur] == '#') {
                int len = stoi(s.substr(cur_start, cur-cur_start));
                res.push_back(s.substr(cur+1, len));
                cur += len+1;
                cur_start = cur;
            }
            else cur++;
        }
        return res;
    }
};

int main() {
  Solution s;
  
  //vector<string> t = {"#$%", "", "23479sdfhi897"};
  vector<string> t = {};
  string r = s.encode(t);
  cout<<r<<endl;
  vector<string> rr = s.decode(r);
  print_v(rr);

  return 0;
}
