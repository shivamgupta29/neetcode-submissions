class Solution {
public:
    bool topoSort(unordered_map<int, vector<int>> &adj, int n, vector<int> &indeg){
        queue<int> q;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(indeg[i] == 0){
                q.push(i);
                cnt++;
            }
        }
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto &v: adj[u]){
                indeg[v]--;
                if(indeg[v]==0){
                    q.push(v);
                    cnt++;
                }
            }
        }
        return (cnt == n) ? true : false; 
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> indeg(numCourses, 0);
        for(auto &p :prerequisites){
            int u = p[1];
            int v = p[0];
            adj[u].push_back(v);
            indeg[v]++;
        }
        return topoSort(adj, numCourses, indeg);
    }
};
