class Solution {
public:
    
    //Brute force - O(N*N)
//     int numberOfArithmeticSlices(vector<int>& nums) {
//         int n = nums.size(), count = 0;
//         if(n<3) return 0;
        
//         for(int i=0;i<=n-3;i++){
//             //curr and next
//             int diff = nums[i+1] - nums[i];
            
//             //here we need atleast 3 elements, so range is n, if it is exactly 3, then j<=2
//             for(int j = i+2;j<n;j++){
//                 //curr and prev
//                 if(nums[j] - nums[j-1] == diff) count++;
//                 else break;
//             }
//         }
//         return count;
//     }
    
    //DP version
    int numberOfArithmeticSlices(vector<int> &nums){
        int n = nums.size();
        if(n<3) return 0;
        
        vector<int> dp(n, 0);
        int count = 0;
        
        if(nums[2]-nums[1] == nums[1]-nums[0]) dp[2] = 1;
        count = dp[2];
        
        for(int i=3;i<n;i++){
            if(nums[i]-nums[i-1]==nums[i-1] - nums[i-2]) dp[i] = dp[i-1] + 1;
            count+=dp[i];
        }
        return count;
    }
};