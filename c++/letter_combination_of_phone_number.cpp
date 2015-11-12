#include<map>
#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
      vector<string> ret;
      map<char, string> mapping;
      mapping['2'] = "abc";
      mapping['3'] = "def";
      mapping['4'] = "ghi";
      mapping['5'] = "jkl";
      mapping['6'] = "mno";
      mapping['7'] = "pqrs";
      mapping['8'] = "tuv";
      mapping['9'] = "wxyz";

      int l = digits.size();
      for (int i = 0; i != l; i++) {
        if (digits[i] >= '2' && digits[i] <= '9') {
          if (ret.empty()) {
            for (int j = 0; j != mapping[digits[i]].size(); j++) {
              ret.push_back(string(1, mapping[digits[i]][j]));
            }
          } else {
            vector<string> tmp(ret.begin(), ret.end());
            ret.clear();
            for (int j = 0; j != mapping[digits[i]].size(); j++) {
              for (int k = 0; k != tmp.size(); k++) {
                ret.push_back(tmp[k]+mapping[digits[i]][j]);
              }
            }
          }
        }
      }
      return ret;
    }
};


int main() {
  Solution s;
  vector<string> r = s.letterCombinations(string("23"));
  for (int i = 0; i != r.size(); i++) {
    cout << r[i] << ",";
  }
  cout << endl;
}
