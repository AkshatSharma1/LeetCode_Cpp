class Solution {
public:
    
    
    int destroyTargets(vector<int>& nums, int space) {
        int n = nums.size();
        int maxi=-1e9;
        int rem=0;
        map<int,int> map;
        for(int i=0; i<n; i++)
        {
            map[nums[i]%space]++;
                maxi=max(maxi,map[nums[i]%space]); 
         }

        int ans=INT_MAX;
        for(int i=0; i<n; i++)
        {
            if(map[nums[i]%space]==maxi)
            {
                ans=min(ans,nums[i]);
            }
        }
        return ans;
    }
};