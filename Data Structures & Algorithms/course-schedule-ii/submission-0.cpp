class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> indeg(numCourses, 0);
        for(auto &p :prerequisites){
            int u = p[1];
            int v = p[0];
            adj[u].push_back(v);
            indeg[v]++;
        }
        queue<int> q;
        int cnt=0;
        vector<int> ans;
        for(int i=0;i<numCourses;i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int u = q.front();
            q.pop();
            ans.push_back(u);
            cnt++;
            for(auto &v: adj[u]){
                indeg[v]--;
                if(indeg[v]==0){
                    q.push(v);
                }
            }
        }
        if(cnt==numCourses) return ans;
        return {};
    }
};
