class Solution {
public:
    
    int bfs(int node, int n, vector<pair<int,int>> adj[]){
        queue<int> q;
        q.push(node);
        int count = 0;
        vector<bool> visited(n, false);
        visited[node] = true;
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            
            for(auto &[neigh, sign]: adj[it]){
                if(!visited[neigh]){
                    visited[neigh] = true;
                    q.push(neigh);
                    count+=sign;
                }
            }
        }
        return count;
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        //make a graph
        vector<pair<int,int>> adj[n];
        
        for(auto& con: connections){
            adj[con[0]].push_back({con[1], 1});
            adj[con[1]].push_back({con[0], 0}); //revered edge
        }
        
        return bfs(0, n, adj);
    }
};