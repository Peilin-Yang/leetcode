#include<vector>
#include<iostream>
#include<unordered_set>
#include<queue>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        queue<string> q;
        int s = beginWord.size();
        int r = 1;
        q.push(beginWord);
        while  (!q.empty()) {
            cout << " -+-+-+-+-+-+-+ " << endl;
            int num = q.size();
            bool found = false;
            for (int i = 0; i < num; i++) {
                    string tmp = q.front();
                    cout << "tmp:" << tmp << endl;
                    q.pop();
                    for (int k = 0; k != s; k++) {
                        char c = tmp[k];
                        for (int l = 0; l < 26; l++) {
                            tmp[k] = 'a'+l;
		            unordered_set<string>::iterator it;
                            it = wordList.find(tmp);
                            if (it != wordList.end()) {
                                if (*it == endWord) {
			            cout << *it << ",";
                	            return r+1;
                                } else {
                                    q.push(tmp);
                                    wordList.erase(it);
                                }
                            }
                        }
                        tmp[k] = c;
                    }
            }
            r++;
        }
        return 0;
    }
};

void print_r(queue<string> &r) {
  while(!r.empty()) {
    cout << r.front() << endl;
    r.pop();
  }
}

int main() {
  Solution s;

  string a[] = {"hot","cog","dot","dog","hit","lot","log"};
  unordered_set<string> n(a,a+sizeof(a)/sizeof(string));
  int r = s.ladderLength("hit", "cog", n);
  cout << r << endl;

  return 0;
}
