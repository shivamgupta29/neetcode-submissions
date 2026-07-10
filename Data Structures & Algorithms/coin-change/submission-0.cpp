class Solution {
public:
    vector<int> memo;

    int solve(vector<int>& coins, int rem) {
        if (rem == 0) return 0;
        
        if (rem < 0) return INT_MAX;

        if (memo[rem] != -1) {
            return memo[rem];
        }

        int minCoins = INT_MAX;
        for (int coin : coins) {
            int res = solve(coins, rem - coin);
            
            if (res != INT_MAX) {
                minCoins = min(minCoins, 1 + res);
            }
        }
        memo[rem] = minCoins;
        return minCoins;
    }

    int coinChange(vector<int>& coins, int amount) {
        memo.assign(amount + 1, -1);

        int result = solve(coins, amount);

        return (result == INT_MAX) ? -1 : result;
    }
};   