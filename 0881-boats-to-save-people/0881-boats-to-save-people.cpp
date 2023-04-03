class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin(), people.end());
        int count = 0;
        int i=0, j = n-1;
        while(i<=j){
            count++;
            
            if(people[i] + people[j]<=limit) i++; //check for second
            j--;
        }
        
        
        return count;
    }
};