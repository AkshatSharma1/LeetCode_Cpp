class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        unordered_map<int,int> mp;
        int n = nums.size();
        
        if(n<3 || nums[0]>0) return {};
        
        for (int i = 0; i < n; i++)
            mp[nums[i]] = i;
        
        for(int i=0;i<n-2;i++){
            if(i!=0 && nums[i]==nums[i-1]) continue;
            if(nums[i]>0) return ans;
            
            for(int j = i+1;j<n-1;j++){
                int val = -1*(nums[i]+nums[j]);
                if(j!=i+1 && nums[j]==nums[j-1]) continue; //no dup
                if(mp.find(val)!=mp.end() && mp[val]>j){
                    ans.push_back({nums[i], nums[j], val});
                }
            }
        }
        return ans;
    }
};