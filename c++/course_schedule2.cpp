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
    graph make_graph(int n,vector<pair<int, int>>& pres ) {
        graph g(n);
        for (int i = 0; i < pres.size(); i++) {
            g[pres[i].first].insert(pres[i].second);
        }
        return g;
    }
    bool cycle(graph& g, vector<bool>& path, vector<bool>& visited, vector<int>& order, int i) {
        if (!visited[i]) {
            path[i] = visited[i] = true;
            for (auto it = g[i].begin(); it != g[i].end(); it++) {
                if (path[*it] || cycle(g, path, visited, order, *it)) return true;
            }
            order.push_back(i);
        }
        path[i] = false;
        return false;
    }
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<bool> path(numCourses, false);
        vector<bool> visited(numCourses, false);
        vector<int> res;
        graph g = make_graph(numCourses, prerequisites);
        print_graph(g);
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (cycle(g, path, visited, res, i)) {
                    return vector<int>();
                }
            }
        }
        return res;
    }
};

int main() {
  Solution s;

  vector<pair<int, int> > t;
  t.push_back(make_pair(1,0));
  //t.push_back(make_pair(0,1));
  vector<int> r;
  r = s.findOrder(2, t);
  print_r(r);

  return 0;
}
