class Solution {
public:
    
    
    //Recursion
//     int helper(int i, int j, vector<vector<int>> &grid){
        
//         int sumUp = 101,sumLeft = 101;
        
//         //Base case
//         if(i==0 && j==0) return grid[0][0];
//         // if(i<0 || j<0) return 101;
        
//         //going up
//         if(i>0) sumUp = grid[i][j] + helper(i-1, j, grid);
         
//         if(j>0) sumLeft = grid[i][j] + helper(i, j-1, grid);
        
        
//         return min(sumUp, sumLeft);
        
//     }
    
    //Memoization
    int helper(int i, int j, vector<vector<int>> &grid, vector<vector<int>>& dp){
        
        int sumUp = 1e9,sumLeft = 1e9;
        
        //Base case
        if(i==0 && j==0) return grid[0][0];
        // if(i<0 || j<0) return 101;
        
        if (dp[i][j]!=-1) return dp[i][j];
        
        //going up
        if(i>0) sumUp = grid[i][j] + helper(i-1, j, grid, dp);
         
        if(j>0) sumLeft = grid[i][j] + helper(i, j-1, grid, dp);
        
        
        return dp[i][j] = min(sumUp, sumLeft);
        
    }
    
    
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        return helper(n-1, m-1, grid, dp);
    }
};