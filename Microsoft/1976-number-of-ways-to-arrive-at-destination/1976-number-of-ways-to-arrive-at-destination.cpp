class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // to store adjacent node and time to reach it
        vector<pair<int, long long>> adj[n];
        for (auto &road: roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }
        // min heap for djikstra's algo, storing the time and the adjacent node
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        // dist to store the distance from node 0 to a node i-1 (given by index) for djikstra, initially inf
        vector<long long> dist(n, 1e18), ways(n, 0);
        // dist from node 0 to 0 is 0, and ways to reach 0 is 1
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});
        long long mod = 1e9+7;
        while (!pq.empty()) {
            long long d = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();
            for (auto it: adj[currNode]) {
                int node = it.first;
                long long edgeWeight = it.second;
                
                // updating for min dist in djikstra
                if (d + edgeWeight < dist[node]) {
                    dist[node] = d + edgeWeight;
                    // pushing node into pq
                    pq.push({dist[node], node});
                    // the ways to reach the node for the first time will be the ways to reach its previous node, since in order to reach node, you came via path from currNode
                    ways[node] = ways[currNode];
                }
                else if (d + edgeWeight == dist[node]) {
                    // if we come across another shortest path we need to update the ways
                    // since there may be number of ways to reach currNode from its previous nodes, we add them to get the ways to reach node
                    ways[node] = (ways[node] + ways[currNode]) % mod;
                }
            }
        }
        // return the ways to reach dest node
        return ways[n-1] % mod;
    }
};