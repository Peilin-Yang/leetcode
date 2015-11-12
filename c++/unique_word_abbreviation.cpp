#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

class ValidWordAbbr {
private:
    unordered_map<string, unordered_set<string> > m;
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for (int i = 0; i < dictionary.size(); i++) {
            int ss = dictionary[i].size();
            string abbr = dictionary[i][0]+to_string(ss)+dictionary[i][ss-1];
            m[abbr].insert(dictionary[i]);
        }
    }

    bool isUnique(string word) {
        int ss = word.size();
        string abbr = word[0]+to_string(ss)+word[ss-1];
        return m[abbr].count(word) == m[abbr].size();
    }
};

int main() {
  vector<string> d = {"deer", "door", "cake", "card"};
  ValidWordAbbr vwa(d);
  cout << boolalpha << vwa.isUnique("dear") << endl;
  cout << boolalpha << vwa.isUnique("cart") << endl;
  cout << boolalpha << vwa.isUnique("cane") << endl;
  cout << boolalpha << vwa.isUnique("make") << endl;

  return 0;
}
