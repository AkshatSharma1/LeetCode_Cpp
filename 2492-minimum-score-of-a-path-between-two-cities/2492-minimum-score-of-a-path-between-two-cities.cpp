class Solution {
    
private:
    vector<int> parent;
    
    void make_set(int v){
        parent[v] = v;
    }
    
    int find_set(int v){
        if (v == parent[v])
            return v;
        return find_set(parent[v]);
    }
    
    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        // if (a != b)
        //     parent[b] = a;
        
        //here we need to check if first value is less or more than second
        if(a<b){
            parent[b] = a;
        }
        else{
            parent[a] = b;
        }
    }
    
public:
    
    //Union find syntax
    int minScore(int n, vector<vector<int>>& roads) {
        
        parent.resize(n+1);
        
        //initialise the parent array with all cities
        for(int i=1;i<=n;i++){
            make_set(i);
        }
        
        //now union logic implementation
        for(auto &road: roads){
            union_sets(road[0], road[1]);
        }
        
        //now we need to start from '1' city and reach till 'n' city maintaining minDist
        int city = find_set(1), minDist = INT_MAX;
        
        for(auto &road: roads){
            if(find_set(road[0])==city){
                minDist = min(minDist, road[2]);
            }
        }
        return minDist;
    }
};