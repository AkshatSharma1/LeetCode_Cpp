class Solution {
public:
    
    void dfs(int node, vector<bool> &visited, vector<int> adj[],long long &nodeCount){
        visited[node] = true;
        nodeCount++;
        for(auto it: adj[node]){
            if(!visited[it]){
                dfs(it, visited, adj, nodeCount);
            }
        }
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        long long pairs = 0;
        long long sumTillNow = 0;
        long long nodeCount = 0;
        
        for(auto &e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        vector<bool> visited(n, false);
        
        //dfs
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i, visited, adj, nodeCount);
                pairs += sumTillNow * nodeCount;
                sumTillNow += nodeCount;
                nodeCount = 0; //for new component
            }
        }
        return pairs;
    }
};