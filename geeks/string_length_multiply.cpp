#include<vector>
#include<unordered_map>
#include<bitset>
#include<iostream>

using namespace std;

class Solution {
public:
    long long string_to_long(string s) {
        long long res;
        bitset<26> b;
        for (int i = 0; i < s.size(); i++) {
            b[s[i]-'a'] = 1;
        }
        return b.to_ullong();
    }
    int string_length_multiply(vector<string>& strings) {
        unordered_map<string, long long> m;
        for (int i = 0; i < strings.size(); i++) {
            m[strings[i]] = string_to_long(strings[i]);
        }
        for (int i = 0; i < strings.size(); i++) {
            for (int j = i; j < strings.size(); j++) {
                cout << strings[i] << " " << strings[j] << endl;
                cout << m[strings[i]] << " " << m[strings[j]] << endl;
                cout << (m[strings[i]] & m[strings[j]]) << endl;
            }
        }
    }
};

int main() {
  Solution s;

  vector<string> t = {"abcd", "owretuio", "asef"};
  s.string_length_multiply(t);
  return 0;
}
