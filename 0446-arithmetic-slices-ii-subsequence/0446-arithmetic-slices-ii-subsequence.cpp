#define DEFAULT_VALUE 0
class Solution {
public:
    
    //Brute force - O(n*n*n)
    // int numberOfArithmeticSlices(vector<int>& nums) {
    //     int n = nums.size();
    //     int count = 0;
    //     for (int i = 0; i < n-2; i++) {
    //         for (int j = i+1; j < n-1; j++) {
    //             int diff = nums[j] - nums[i];
    //             int length = 2;
    //             for (int k = j+1; k < n; k++) {
    //                 if (nums[k] - nums[j] == diff) {
    //                     nums[j] = nums[k];
    //                     length++;
    //                     if (length >= 3) {
    //                         count++;
    //                     }
    //                 }
    //             }
    //         }
    //     }
    //     return count;
    // }
    
    
    //DP way
    int numberOfArithmeticSlices(vector<int>& nums){
        int n = nums.size();
        int count = 0;
        
        //use hashmap array instead
        //vector<unordered_map<int,int>> mp(n);
        unordered_map<int,int> mp[n];
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                long diff = (long)nums[i] - (long)nums[j];
                
                if(diff<=INT_MIN || diff>=INT_MAX) continue;
                
                auto it = mp[j].find((int)diff);
                
                int slicesEndingAtJ = it==end(mp[j])?0:it->second;
                
                mp[i][(int)diff] += slicesEndingAtJ + 1;
                
                count+=slicesEndingAtJ;
            }
        }
        return count;
    }
    
};