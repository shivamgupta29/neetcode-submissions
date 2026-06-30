class Solution {
public:
    vector<int> t;
    int climb(int idx, vector<int>& cost){
        if(idx >= cost.size()) return 0;
        if(t[idx] != -1) return t[idx];
        int a = cost[idx] + climb(idx+1, cost);
        int b = cost[idx] + climb(idx+2, cost);
        return t[idx] = min(a, b);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        t.resize(cost.size()+1, -1);
        return min(climb(0, cost), climb(1, cost));
    }
};
