class Solution {
public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         vector<vector<int>> ans;
//         unordered_map<int,int> mp;
//         int n = nums.size();
        
//         if(n<3 || nums[0]>0) return {};
        
//         for (int i = 0; i < n; i++)
//             mp[nums[i]] = i;
        
//         for(int i=0;i<n-2;i++){
//             if(i!=0 && nums[i]==nums[i-1]) continue;
//             if(nums[i]>0) return ans;
            
//             for(int j = i+1;j<n-1;j++){
//                 int val = -1*(nums[i]+nums[j]);
//                 if(j!=i+1 && nums[j]==nums[j-1]) continue; //no dup
//                 if(mp.find(val)!=mp.end() && mp[val]>j){
//                     ans.push_back({nums[i], nums[j], val});
//                 }
//             }
//         }
//         return ans;
//     }
    
    //using 2 pointer
    vector<vector<int>> threeSum(vector<int> &nums){
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        
        for(int i=0;i<nums.size()-2;i++){
            
            if(nums[i]>0) return ans;
            
            //condition to operate is if my next ith element is not same as prev one
            if(i==0 || (i>0 && nums[i]!=nums[i-1])){
                
                //take low and high pointer
                int low = i+1, high = nums.size()-1, sum = 0 - nums[i];

                while(low<high){
                    if(nums[low] + nums[high] == sum){
                        ans.push_back({nums[i], nums[low], nums[high]});
                        //now if next low is same as prev or next high is same sa prev, skip till we get a new one
                    
                        while(low<high && nums[low]==nums[low+1]) low++;
                        while(low<high && nums[high]==nums[high-1]) high--;

                        //normally
                        low++;
                        high--;
                    }
                    else if(nums[low] + nums[high] < sum) low++;
                    else high--;
                }
            }
        }
        return ans;
    }
};