class UnionFindDSU{
public:
    vector<int> parent, rank;
    UnionFindDSU(int n){
        parent.resize(n);
        rank.resize(n, 0);

        for(int i=0;i<n;i++){
            parent[i] = i; //or make_set(i);
        }
    }

    int find_set(int v){
        if(v == parent[v])
            return v;
        return  find_set(parent[v]);
    }

    void union_sets(int a, int b){
        int rootA = find_set(a);
        int rootB = find_set(b);

        if(rank[rootA]>rank[rootB]){
            parent[rootB] = rootA;
        }
        else if(rank[rootA] < rank[rootB]){
            parent[rootA] = rootB;
        }
        else{
            parent[rootA] = rootB;
            rank[rootB]++;
        }
    }
};

class Solution {
    
public:
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        if(connections.size() < n-1) return -1;
        
        UnionFindDSU ds(n);
        

        //union sets
        for(auto &con: connections){
            // int u = ds.find_set(con[0]);
            // int v = ds.find_set(con[1]);
            ds.union_sets(con[0], con[1]);
        }
        
        //now since all components are joined, so parents array will contain value other than otself it is connected, if not then disconnecetd
        
        int disconnected = 0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i) disconnected++;
        }
        return disconnected - 1;
    }
};