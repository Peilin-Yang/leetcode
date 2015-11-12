#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

void print_solution(vector<vector<bool> >& flags) {
  //cout << "i:" << flags.size() << endl;
  for(int i = 0; i != flags.size(); i++) {
    //cout << "j:" << flags[i].size() << endl;
    for(int j = 0; j != flags[i].size(); j++) {
      cout << flags[i][j] << ",";
    }
    cout << endl;
  }
}

void print_b(vector<vector<bool> >& r) {
  for (int i = 0; i != r.size(); i++) {
    for (int j = 0; j != r[i].size(); j++) {
      cout << r[i][j] << ",";
    }
    cout << endl;
  }
}

void print_r(vector<string>& r) {
  for (int i = 0; i != r.size(); i++) {
      cout << r[i] << ",";
  }
  cout << endl;
}

class TrieNode {
public:
    bool is_word;
    bool available;
    TrieNode *next[26];
    // Initialize your data structure here.
    TrieNode() {
        memset(next, 0, sizeof(next));
        is_word = false;
        available = false;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *p = root;
        for (int i = 0; i != word.size(); i++) {
            int c = word[i] - 'a';
            if (!p->next[c]) {
                p->next[c] = new TrieNode();
            }
            p = p->next[c];
        }
        p->is_word = true;
        p->available = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *p = root;
        for (int i = 0; i != word.size() && p; i++) {
            int c = word[i] - 'a';
            if (!p->next[c]) return false;
            p = p->next[c];
        }
        if (p->is_word && p->available) {
            p->available = false;
            return true;
        }
        return false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *p = root;
        for (int i = 0; i != prefix.size() && p; i++) {
            int c = prefix[i] - 'a';
            if (!p->next[c]) return false;
            p = p->next[c];
        }
        return true;
    }

private:
    TrieNode* root;
};

class Solution {
public:
    void e(vector<vector<char> >& board, Trie& trie, int row, int col, string r, vector<string>& res) {
        if (row >= board.size() || row < 0 || col < 0 || col >= board[0].size() || !trie.startsWith(r)  || board[row][col] == '\0') {
            return;
        }
        char c = board[row][col];
        r += c;
        cout << "row:" << row << " col:" << col << " r:" << r << endl;
        if (trie.search(r)) {
            res.push_back(r);
        }
        board[row][col] = '\0';
        e(board, trie, row+1, col, r, res);
        e(board, trie, row-1, col, r, res);
        e(board, trie, row, col-1, r, res);
        e(board, trie, row, col+1, r, res);
        board[row][col] = c;
        r = r.substr(0, r.size()-1);
    }
    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
        Trie trie;
        for (int i = 0; i != words.size(); i++) {
            trie.insert(words[i]);
        }
        //cout << trie.search(words[0]);
        vector<string> r;
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i != m; i++) {
            for (int j = 0; j != n; j++) {
                string tmp;
                e(board, trie, i, j, tmp, r);
            }
        }
        sort(r.begin(), r.end());
        return r;
    }
};

int main() {
  Solution s;

  vector<char> v1;
  v1.push_back('o');
  v1.push_back('a');
  v1.push_back('a');
  v1.push_back('n');
  vector<char> v2;
  v2.push_back('e');
  v2.push_back('t');
  v2.push_back('a');
  v2.push_back('e');
  vector<char> v3;
  v3.push_back('i');
  v3.push_back('h');
  v3.push_back('k');
  v3.push_back('r');
  vector<char> v4;
  v4.push_back('i');
  v4.push_back('f');
  v4.push_back('l');
  v4.push_back('v');

  vector<vector<char> > v;
  v.push_back(v1);
  v.push_back(v2);
  v.push_back(v3);
  v.push_back(v4);

  vector<string> test;
  test.push_back("oath");
  test.push_back("pea");
  test.push_back("eat");
  test.push_back("rain");
  vector<string> r;

  r = s.findWords(v, test);
  print_r(r);

  cout << endl << "+++++++++++++++++++++++" << endl << endl;

  v.clear();
  v1.clear();
  v1.push_back('a');
  v.push_back(v1);
  test.clear();
  test.push_back("a");

  r = s.findWords(v, test);
  print_r(r);

  cout << endl << "+++++++++++++++++++++++" << endl << endl;

  v.clear();
  v1.clear();
  v1.push_back('a');
  v1.push_back('a');
  v.push_back(v1);
  test.clear();
  test.push_back("a");

  r = s.findWords(v, test);
  print_r(r);

  cout << endl << "+++++++++++++++++++++++" << endl << endl;

  v.clear();
  v1.clear();
  v2.clear();
  v1.push_back('a');
  v1.push_back('b');
  v2.push_back('c');
  v2.push_back('d');
  v.push_back(v1);
  v.push_back(v2);
  test.clear();
  test.push_back("ab");
  test.push_back("cb");
  test.push_back("ad");
  test.push_back("bd");
  test.push_back("ac");
  test.push_back("ca");
  test.push_back("da");
  test.push_back("bc");
  test.push_back("db");
  test.push_back("adcb");
  test.push_back("dabc");
  test.push_back("abb");
  test.push_back("acb");

  r = s.findWords(v, test);
  print_r(r);

  return 0;
}
