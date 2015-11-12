#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<cstdio>

using namespace std;

void p(vector<bool> r) {
  for (int i = 0; i < r.size(); i++) cout << r[i] << ",";
  cout << endl;
}

void print_r(vector<int> r) {
  for (int i = 0; i < r.size(); i++) cout << r[i] << ",";
  cout << endl;
}

void print_graph(unordered_map<int, unordered_set<int> >& graph) {
  cout << "---------- Print Graph ----------" << endl;
  for (auto i = graph.begin(); i != graph.end(); i++) {
    cout << (char)(i->first+'a') << "->[";
    for (auto it2 = i->second.begin(); it2 != i->second.end(); it2++) {
      cout << (char)(*it2+'a') <<",";
    }
    cout << "]" << endl;
  }
  cout << "---------- Print Graph ----------" << endl;
}

class Solution {
private:
    typedef unordered_map<int, unordered_set<int>> graph;
    graph make_graph(vector<string>& words) {
        graph g;
        if (words.empty()) return g;
        for (int i = 1; i < words.size(); i++) {
            string before = words[i-1];
            string cur = words[i];
            bool found = false;
            for (int j = 0; j < max(before.size(), cur.size()); j++) {
                if (j < before.size() && g.find(before[j]-'a') == g.end()) {g[before[j]-'a'] = unordered_set<int>();}
                if (j < cur.size() && g.find(cur[j]-'a') == g.end()) {g[cur[j]-'a'] = unordered_set<int>();}
                if (j < before.size() && j < cur.size() && cur[j] != before[j] && !found) {
                    int c1 = cur[j]-'a';
                    int c2 = before[j]-'a';
                    cout << cur[j] << " " << before[j] << endl;
                    g[c1].insert(c2);
                    found = true;
                }
            }
        }
        print_graph(g);
        return g;
    }
    bool has_cycle(graph& g, vector<bool>& path, vector<bool>& visited, int i, string &res) {
        if (!visited[i]) {
            path[i] = visited[i] = true;
            for (auto it = g[i].begin(); it != g[i].end(); it++) {
                if (path[*it] || has_cycle(g, path, visited, *it, res)) return true;
            }
            res += i+'a';
        }
        path[i] = false;
        return false;
    }
public:
    string alienOrder(vector<string>& words) {
        graph g = make_graph(words);
        vector<bool> path(g.size(), false);
        vector<bool> visited(g.size(), false);
        string res;
        for (auto i = g.begin(); i != g.end(); i++) {
            if (has_cycle(g, path, visited, i->first, res)) return "";
        }
        return res;
    }
};

int main() {
  Solution s;

  vector<string> t = {"wrt", "wrf", "er", "ett", "rftt"};
  //vector<string> t = {"z", "z"};
  cout <<  s.alienOrder(t) << endl;

  return 0;
}
