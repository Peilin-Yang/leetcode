#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
      vector<int> ret;
      int w_len = words.size();
      int s_len = s.size();
      int word_len = words[0].size();
      if (word_len*w_len > s_len || w_len == 0) return ret;
      unordered_map<string, int> words_map;
      for (int i = 0; i != w_len; i++) {
        if (words_map.find(words[i]) == words_map.end()) {
          words_map[words[i]] = 1;
        } else {
          words_map[words[i]]++;
        }
      }
      int idx = 0;
      while (idx != s_len && s_len-idx >= word_len*w_len) {
        bool found = true;
        unordered_map<string, int> local_map;
        for(int i = 0; i != w_len; i++) {
          string sub = s.substr(idx+i*word_len, word_len);
          if (words_map.find(sub) == words_map.end()) {
            found = false;
            break;
          }
          if (local_map.find(sub) == local_map.end()) {
            local_map[sub] = 1;
          } else {
            local_map[sub]++;
          }
          if (local_map[sub] > words_map[sub]) {
            found = false;
            break;
          }
        } 
        if (found) {
          ret.push_back(idx);
        }          
        idx++;
      }
      return ret;
    }
};

int main() {
  Solution s;
  string a[] = {"foo", "bar"};
  string b[] = {"a", "b"};
  vector<string> words(b, b+sizeof(b)/sizeof(string));
  string t;
  
  t = "barfoothefoobarman";
  t = "aaa";
  
  vector<int> indices = s.findSubstring(t, words);
  for (int i = 0; i != indices.size(); i++) {
    cout << indices[i] << ",";
  }
  cout << endl;

  return 0;
}
