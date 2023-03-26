class Solution {
public:
     
    void seive_algo(vector<bool> &prime, int n)
    {
        prime[0] = prime[1] = false;
        for (int p = 2; p * p <= n; p++) {
        // If prime[p] is not changed, then it is a prime
            if (prime[p] == true) {
                // Update all multiples of p greater than or
                // equal to the square of it numbers which are
                // multiple of p and are less than p^2 are
                // already been marked.
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }
    }

    bool primeSubOperation(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<bool> isPrime(1005, true);
        seive_algo(isPrime, 1005);

        vector<int> prime;
        for(int i=0; i<1004; i++)
            if(isPrime[i]) prime.push_back(i);
        
        //printing primes
        // for(int j = 0;j<prime.size();j++) cout<<prime[j]<<" ";
        // cout<<endl;
        
//         for(int i=n-2;i>=0;i--){
            
//             //first check if prev is bigger than nums[i]
//             if(nums[i+1]>nums[i]){
//                 continue;
//             }
            
//             //find prime big possible less than prev
//             auto p = lower_bound(prime.begin(), prime.end(), nums[i] - nums[i+1]+1);
            
//             if(p==prime.end()) return false;
            
//             nums[i] -= prime[(p - prime.begin())];    
            
//             if(nums[i]<=0) return false;
//         }
        
        for(int i=0;i<n;i++){
            if(i && nums[i]<=nums[i-1]) return false;
            
            auto p = 0;
            
            if(i==0) p = lower_bound(prime.begin(), prime.end(), nums[i] - 0) - prime.begin();
            else p = lower_bound(prime.begin(), prime.end(), nums[i] - nums[i-1]) - prime.begin();
            
            if(p!=0){
                nums[i] -= prime[p-1];
            }
        }
        
        return true;
        
    }
};