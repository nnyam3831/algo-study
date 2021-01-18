#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph g = buildGraph(numCourses, prerequisites);
        vector<bool> todo(numCourses, false), done(numCourses, false);
        for(int i = 0; i < numCourses; i++) {
            if (isCyclic(g, todo, done, i)) return false;
        }

        return true;
    }

private:
    typedef vector<vector<int>> graph;
    
    graph buildGraph(int numCourses, vector<vector<int>>& prerequisites) {
        graph g(numCourses);
        for(auto p : prerequisites) {
            g[p[1]].push_back(p[0]);
        }
        return g;
    }

    bool isCyclic(graph& g, vector<bool>& todo, vector<bool>& done, int node) {
        if (todo[node]) return true;
    
        if (done[node]) return false;

        todo[node] = done[node] = true;
        for(int v : g[node]) {
            if (isCyclic(g, todo, done, v)) return true;
        }

        todo[node] = false;
        return false;
    }
};