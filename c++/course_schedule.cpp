#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<cstdio>

using namespace std;

void p(vector<bool> r) {
  for (int i = 0; i < r.size(); i++) cout << r[i] << ",";
  cout << endl;
}

void print_graph(vector<unordered_set<int> >& graph) {
  cout << "---------- Print Graph ----------" << endl;
  for (int i = 0; i != graph.size(); i++) {
    cout << i << "->[";
    for (auto it2 = graph[i].begin(); it2 != graph[i].end(); it2++) {
      cout << *it2 <<",";
    }
    cout << "]" << endl;
  }
  cout << "---------- Print Graph ----------" << endl;
}

class Solution {
public:
    typedef vector<unordered_set<int> > graph;
    graph make_graph(int n, vector<pair<int, int> >& p) {
        graph g(n);
        for (int i = 0; i < p.size(); i++) {
            g[p[i].first].insert(p[i].second);
        }
        print_graph(g);
        return g;
    }
    bool cyclic(graph& g, vector<bool>& path, vector<bool>& visited, int i) {
        path[i] = visited[i] = true;
        for (auto it = g[i].begin(); it != g[i].end(); ++it) {
            if (!visited[*it] && cyclic(g, path, visited, *it)) return true;
            else if (path[*it]) return true;
        } 
        path[i] = false;
        p(path);
        return false;
    }
    bool canFinish(int numCourses, vector<pair<int, int> >& pres) {
        graph g = make_graph(numCourses, pres);
        vector<bool> path(numCourses, false);
        vector<bool> visited(numCourses, false);
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (cyclic(g, path, visited, i)) return false;
            }
        }
        return true;
    }
};

int main() {
  Solution s;

  vector<pair<int, int> > t;
  //t.push_back(make_pair(1,0));
  //t.push_back(make_pair(0,1));

  cout << std::boolalpha << s.canFinish(1, t) << endl;

  return 0;
}
