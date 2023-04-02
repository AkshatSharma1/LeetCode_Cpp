class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        // cout<<ceil(16*1.0/3);
        // vector<int> arr = {1,2,3,4,5};
        // cout<<lower_bound(arr.begin(), arr.end(), ceil(7*1.0/5)) - arr.begin();
        
        int n = spells.size();
        int m = potions.size();
        sort(potions.begin(), potions.end());
        vector<int> pairs(n, 0);
        
        for(int i=0;i<n;i++){
            
            int count = 0;
            
            int leastStrengthReq = lower_bound(potions.begin(), potions.end(), ceil(success*1.0/spells[i])) - potions.begin();
            
            count = m - leastStrengthReq;
            // cout<<count<<" ";
            pairs[i] = count;
            
        }
        
        return pairs;
    }
};