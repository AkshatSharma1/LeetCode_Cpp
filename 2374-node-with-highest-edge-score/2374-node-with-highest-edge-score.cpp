class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        
        vector<int> adj[n];
        
        //its same as edges array
        // for(int i=0;i<n;i++){
        //     adj[i].push_back(edges[i]);
        // }
        
        vector<long long> indegree(n,0);
        
        long long maxVal = LONG_MIN;
        int minIdx = -1;
        
        for(int i=0;i<n;i++){
            indegree[edges[i]] += i;
        }
        
        for(int i=0;i<n;i++)
        {
            if(maxVal < indegree[i])
            {
                maxVal = indegree[i];
                minIdx = i;
            }
                
        }
        
        return minIdx;
        
    }
};