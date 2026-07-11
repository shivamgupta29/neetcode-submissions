class Solution {
public:
    vector<vector<int>> ans;
    int K;
    int N;
    void solve(vector<int> &temp, int idx){
        if(temp.size() == K){
            ans.push_back(temp);
            return;
        }
        for(int i=idx;i<=N;i++){
            temp.push_back(i);
            solve(temp, i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        K = k;
        N = n;
        vector<int> temp;
        solve(temp, 1);
        return ans;
    }
};