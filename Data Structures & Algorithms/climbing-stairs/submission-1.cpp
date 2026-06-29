class Solution {
public:
    vector<int> m;
    int solve(int n){
        if(n < 0) return 0;
        if(n == 0) return 1;
        if(m[n] != -1) return m[n];
        return m[n] = solve(n-1) + solve(n-2);
    }
    int climbStairs(int n) {
        m.assign(n+1, -1);
        return solve(n);
    }
};
