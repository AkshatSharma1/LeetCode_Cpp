class Solution {
public:
    const int MOD = 1e9+7;
    //Recursive way
    int cutWays(int row, int col, int n, int m, int k, vector<vector<int>> &apples, vector<vector<vector<int>>> &dp){
        
        //Base case: if k is 1 means one slice left. Check if it has enough apples
        if(k==1 && apples[row][col]>=1){
            dp[row][col][k] = 1;
            // return 1;
        }
        
        //Base case 2: no apples left
        if(apples[row][col]<k) dp[row][col][k] = 0;
        
        if(dp[row][col][k]!=-1) return dp[row][col][k];
        
        //Making cuts
        int ans = 0;
        
        //Horizontal cuts
        for(int i=row+1;i<n;i++){
            
            //now check if a cut can be made here
            int cuttingPosition = apples[i][col];
            if(apples[row][col] - cuttingPosition >0) ans = (ans + cutWays(i, col, n,m, k-1, apples,dp))%MOD;            
        }
        
        //Vertical cuts
        for(int i=col+1;i<m;i++){
            
            int cuttingPosition = apples[row][i];
            if(apples[row][col] - cuttingPosition > 0) ans = (ans + cutWays(row, i, n, m, k-1, apples, dp))%MOD;
        }
        
        return dp[row][col][k] = ans;
        // return ans;
    }
    
    
    int ways(vector<string>& pizza, int k) {
        int n = pizza.size();
        int m = pizza[0].size();
        
        vector<vector<int>> apples(n,vector<int>(m, 0));
        
        //Fill apples array
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                //if last box, val is 0 or 1 depending upon availability
                // if((i==n-1 && j==m-1) && pizza[i][j]=='A') apples[i][j] = 1;
                
                if (pizza[i][j] == 'A') {
                    // if there is an apple at this location, mark it as 1
                    apples[i][j] = 1;
                }
                
                if(i==n-1 && j==m-1){
                    // apples[i][j] = (pizza[i][j]=='A')?1:0;
                    continue;
                }
                
                else if(i==n-1){
                    // apples[i][j] += (apples[i][j+1] + (pizza[i][j]=='A')?1:0);
                    apples[i][j] += apples[i][j+1];
                }
                else if(j==m-1){
                    // apples[i][j] += (apples[i+1][j] + (pizza[i][j]=='A')?1:0);
                    apples[i][j]+=apples[i+1][j];
                }
                else{
                    // apples[i][j] += (apples[i+1][j] + apples[i][j+1] - apples[i+1][j+1] + (pizza[i][j]=='A')?1:0);
                    apples[i][j]+=apples[i][j+1] + apples[i+1][j] - apples[i+1][j+1];
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<apples[i][j]<<" ";
            }
            cout<<endl;
        }
        
        //now when apples array is filled, do recursion task
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(k+1,-1)));
        
        return cutWays(0,0,n,m,k,apples, dp);
    }
};