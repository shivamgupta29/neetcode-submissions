class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> outdeg(n+1, 0);
        vector<int> indeg(n+1, 0);
        for(auto vec: trust){
            int a = vec[0];
            int b = vec[1];
            outdeg[a]++;
            indeg[b]++;
        }
        for(int i=1;i<=n;i++){
            if(indeg[i]==n-1 && outdeg[i]==0){
                return i;
            }
        }
        return -1;
    }
};