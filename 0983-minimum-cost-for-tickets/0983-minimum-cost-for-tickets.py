class Solution:
    
    def helper(self,days,costs,i,deepee):
        if i==len(days):
            return 0
        
        if deepee[i]!=-1: return deepee[i]
        ans1=costs[0] + self.helper(days, costs, i+1, deepee) 
        
        curr=i
        for index in range(curr,len(days)):
            if days[index]<days[i]+7:
                curr+=1
            else:
                break

        ans2=costs[1]+self.helper(days, costs, curr, deepee)
        curr=i
        for index in range(curr,len(days)):
            if days[index]<days[i]+30:
                curr+=1
            else:
                break

        ans3=costs[2]+self.helper(days, costs, curr, deepee)
        
        deepee[i] = min(ans1, ans2, ans3)
        
        return deepee[i]
        
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        deepee=[-1 for i in range(len(days)+1)]
        return self.helper(days,costs,0,deepee)