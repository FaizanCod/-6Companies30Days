class Solution {
public:
    
    void findRoot(vector<vector<int>> &adj, vector<bool> &vis, int i, vector<int> &res, vector<int> &path) {
        path.push_back(i);
        if (i == 0) {
            // if we reach the root node
            res = path;         // the currpath taken is the result
            path.pop_back();    // popping the current node pushed
            return;
        }
        vis[i] = true;
        for (int node: adj[i]) {
            // for each node adjacent and unvisited to curr node i,
            // find out the path to root from node
            if (!vis[node])
                findRoot(adj, vis, node, res, path);
        }
        // backtrack if root not found for the path
        vis[i] = false;
        path.pop_back();
    }
    
    void dfsLeaf (vector<vector<int>> &adj, vector<bool> &vis, int currNode, int step, int profit, int &res, unordered_map<int, int> &bobP, vector<int> &amt) {
        bool isLeaf = true;
        vis[currNode] = true;
        
        // if we are on node that has been taken by Bob earlier
        if (bobP.find(currNode) != bobP.end()) {
            // s is the step at which bob reached the currNode
            int s = bobP[currNode];
            // if both reach the currNode at the same time, the cost/gain is divided
            if (s == step)
                profit += amt[currNode] / 2;
            // if Alice reaches first, alice gets the whole
            else if (s > step)
                profit += amt[currNode];
            // if bob reaches first, alice gets nothing
        }
        else
            profit += amt[currNode];
        
        for (int node: adj[currNode]) {
            // for each node adjacent and non visited to currNode, we run dfs for that node
            if (!vis[node]) {
                // step incremented
                dfsLeaf(adj, vis, node, step+1, profit, res, bobP, amt);
                isLeaf = false;
            }
        }
        
        vis[currNode] = false;      // backtrack
        
        if (isLeaf)
            res = max(res, profit);
    }
    
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        // BOB can follow only one path upto the root node, while Alice has choices to make her profit maximum, as she can go to any leaf node (optimally to the maximum profit node)
        int n = amount.size();
        // no of nodes = n
        vector<vector<int>> adj(n+1);
        for (auto &edge: edges) {       // bidirected graph for Alice and Bob both
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n, false);     // whether a node was visited or not
        vector<int> bobPath, currPath;
        // bobPath to store the path bob takes upto the root node, currPath as a temp vector for the dfs to find root node
        
        findRoot(adj, visited, bob, bobPath, currPath);
        // finding root from bob to root(0th node), with the path stores in bobPath and the adj, currPath and visited vectors to help in dfs
        unordered_map<int, int> bobP;
        // to keep track of path of Bob, we use a map which maps the path bob had taken for the ith iteration to the ith index
        for (int i=bobPath.size()-1; i>=0; i--)
            bobP[bobPath[i]] = i;
        
        int res = INT_MIN;      // Alice's max net income
        // adj and visited for dfs
        // currnode of Alice = 0, steps taken by Alice = 0, current profit = 0
        // amount and bobP for checking conditions
        // answer in res
        dfsLeaf(adj, visited, 0, 0, 0, res, bobP, amount);
        return res;
    }
};