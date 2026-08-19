class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pendingTasks;
        for(int i=0;i<tasks.size();i++){
            int enq = tasks[i][0];
            pendingTasks.push({enq, i});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> availableTasks;
        vector<int> ans;
        long long time=0;
        while(!availableTasks.empty() || !pendingTasks.empty()){
            while(!pendingTasks.empty() && pendingTasks.top().first <= time){
                int i = pendingTasks.top().second;
                pendingTasks.pop();
                int processTime = tasks[i][1];
                availableTasks.push({processTime, i});
            }
            if(availableTasks.empty()){
                time = pendingTasks.top().first;
                continue;
            }
            auto [processTime, i] = availableTasks.top();
            availableTasks.pop();
            time += processTime;
            ans.push_back(i);
        }
        return ans;
    }
};