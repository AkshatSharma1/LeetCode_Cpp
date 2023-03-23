class Solution {
public:
    
    //Binary search
//     int missingNumber(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
        
//         int low = 0, high = nums.size();
        
//         while(low<high){
//             int mid = (low + high)/2;
            
//             if(nums[mid]>mid) high = mid;
//             else low = mid+1;
//         }
//         return low;
//     }
    
    //O(n) and O(1)
    int missingNumber(vector<int> &nums){
        int n = nums.size();
        int totalSum = nums.size()*(nums.size() + 1)/2;
        int sum = 0;
        cout<<totalSum<<endl;
        
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        
        return totalSum - sum;
    }
};