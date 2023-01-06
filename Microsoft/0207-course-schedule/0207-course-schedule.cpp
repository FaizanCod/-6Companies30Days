bool isCycle(int i, vector<int> adj[], vector<bool> &vis, vector<bool> &dfsVis) {
    vis[i] = true;
    dfsVis[i] = true;
    for (auto node: adj[i]) {             // for each adjacent node, in our case we have just one
        if (!vis[node]) {
            if (isCycle(node, adj, vis, dfsVis))
                return true;                    // if cycle exists return true
        }
        else if (dfsVis[node])
            return true;                        // if vis is true and dfsVis is also true, only then the cycle exists
    }
    dfsVis[i] = false;                          // to signify the current dfs has visited the node, and while tracing back, the dfs can visit the node again (directed graph cycle check)
    return false;
}

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        // finding a cycle in directed graph, if cycle exists, the courses cannot be completed
        vector<int> adj[n];
        for (int i=0; i<prerequisites.size(); i++)
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        vector<bool> visited(n, false), dfsVis(n, false);               // two visited arrays dfsVis for the current dfs getting visited (for a certain recursion call), while visited is the global visited
        for (int i=0; i<n; i++) {
            if (!visited[i]) {
                if (isCycle(i, adj, visited, dfsVis))                // for each node check if cycle exists, if true, return false
                    return false;
            }
        }
        return true;
    }
};