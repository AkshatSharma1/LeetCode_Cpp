class Solution {
public:
    
    int minCost(int indx, vector<int> &days, vector<int> &costs, vector<int> &dp){
        
        int n = days.size();
        int i;
        
        //BASE CASE:
        if(indx >= n) return 0;
        
        if(dp[indx]!=-1) return dp[indx];
        
        //1-day pass
        int dayPass = costs[0] + minCost(indx+1, days, costs, dp);
        
        //7-day pass: skip 7 days if a 7-day pass is bought
        for(i = indx; i < n && days[i]<days[indx] + 7; i++);
        int weekPass = costs[1] + minCost(i, days, costs, dp);
        
        
        //30-Day pass
        for(i = indx; i<n && days[i]<days[indx]+30; i++);
        int monthPass = costs[2] + minCost(i, days, costs, dp);
        
        dp[indx] = min({dayPass, weekPass, monthPass});
        return dp[indx];
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        int n = days.size();
        vector<int> dp(n,-1);
        
        return minCost(0, days, costs, dp);
    }
};