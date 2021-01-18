#include <iostream>
#include <vector>

using namespace std;

// 위상정렬이 정확히 수행된다면 numCourses만큼 반복문을 돈다.
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        graph g = buildGrapgh(numCourses, prerequisites);
        vector<int> degrees = computeIndegrees(g);
        for(int i = 0; i < numCourses; i++) {
            int j = 0;
            for(; j < numCourses; j++) {
                if(!degrees[j]) break;
            }
            if(j == numCourses) return false;
            
            degrees[j]--;
            for(int v : g[j]) {
                degrees[v]--;
            }
        }
        return true;
    }

private:
    typedef vector<vector<int>> graph;

    graph buildGrapgh(int numCourses, vector<vector<int>>  &prerequisites) {
        graph g(numCourses);
        for(auto p : prerequisites) {
            g[p[1]].push_back(p[0]);
        }
        return g;
    }
    
    vector<int> computeIndegrees(graph &g) {
        vector<int> degrees(g.size(), 0);
        for(auto adj : g) {
            for(int v : adj) {
                degrees[v]++;
            }
        }
        return degrees;
    }
}