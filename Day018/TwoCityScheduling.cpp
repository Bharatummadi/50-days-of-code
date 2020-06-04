#define ll long long int
class Solution {
    ll solve(vector<vector<int>>& costs,int ac,int bc,int pos,vector<vector<int>>& dp)
    {
        if(ac<0 || bc<0)
            return 1e6;     //INT_MAX
        if(ac==0 && bc==0)
            return 0;
        if(dp[ac][bc]!=-1)
            return dp[ac][bc];
        
        ll includeA = costs[pos][0] + solve(costs,ac-1,bc,pos+1,dp);
        ll includeB = costs[pos][1] + solve(costs,ac,bc-1,pos+1,dp);
        dp[ac][bc] = min(includeA,includeB);
        return dp[ac][bc];
    }
    
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        int n = costs.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int min_cost = solve(costs,n/2,n/2,0,dp);
        return min_cost;
    }
};