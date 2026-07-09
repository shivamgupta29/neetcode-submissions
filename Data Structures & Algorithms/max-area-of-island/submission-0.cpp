class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int &currArea){
        if(i >= grid.size() || i<0 || j>=grid[0].size() || j<0) return;
        if(grid[i][j] == 0) return;
        currArea++;
        grid[i][j] = 0;
        dfs(grid, i-1, j, currArea);
        dfs(grid, i+1, j, currArea);
        dfs(grid, i, j-1, currArea);
        dfs(grid, i, j+1, currArea);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 0) continue;
                int currArea=0;
                dfs(grid, i, j, currArea);
                maxArea = max(maxArea, currArea);
            }
        }
        return maxArea;
    }
};