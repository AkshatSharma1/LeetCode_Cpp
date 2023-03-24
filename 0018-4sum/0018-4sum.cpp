class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        if(nums.size()<4) return {};
        
        for(int i=0;i<nums.size()-3;i++){
            if(i==0 || (i>0 && nums[i]!=nums[i-1])){
                for(int j=i+1;j<nums.size()-2;j++){
                    
                    //check dup for j
                    if(j==i+1 || (j>i+1 && nums[j]!=nums[j-1])){
                        long long sum = (long long)target - (long long)(nums[i] + nums[j]);

                        int low = j+1, high = nums.size()-1;

                        while(low<high){
                            long long twoSum = nums[low] + nums[high];
                            if(twoSum==sum){
                                ans.push_back({nums[i], nums[j], nums[low], nums[high]});

                                while(low<high && nums[low]==nums[low+1]) low++;
                                while(low<high && nums[high]==nums[high-1]) high--;

                                low++;
                                high--;
                            }
                            else if(twoSum<sum) low++;
                            else high--;
                        }
                    }
                    //now for j, check if j value is not same
                    // while(j+1<nums.size() && nums[j]==nums[j+1]) j++;
                }
            }
        }
        return ans;
    }
};