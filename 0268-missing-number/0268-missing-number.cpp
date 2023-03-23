class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int low = 0, high = nums.size();
        
        while(low<high){
            int mid = (low + high)/2;
            
            if(nums[mid]>mid) high = mid;
            else low = mid+1;
        }
        return low;
    }
};