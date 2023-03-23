class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
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
        vector<vector<int>> result;
        sort(nums.begin(), nums.end()); // Sort the array in non-descending order
        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            // Initialize two pointers left and right
            int left = i + 1, right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    // Skip duplicates
                    while (left < right && nums[left] == nums[left-1]) {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right+1]) {
                        right--;
                    }
                }
                else if (sum < 0) {
                    left++;
                }
                else {
                    right--;
                }
            }
            // Skip duplicates
            while (i < n - 2 && nums[i] == nums[i+1]) {
                i++;
            }
        }
        return result;
    }
};