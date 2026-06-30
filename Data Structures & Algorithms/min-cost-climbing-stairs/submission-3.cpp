class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if (n == 0) return 0;
        if (n == 1) return cost[0];
        if(n==2) return min(cost[0], cost[1]);
        vector<int> dp(n+1);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i=2;i<=n;i++){
            int current_step_cost = (i==n) ? 0 : cost[i];
            dp[i] = current_step_cost + min(dp[i-1], dp[i-2]);
        }
        return dp[n];
    }
};
