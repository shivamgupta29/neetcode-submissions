class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        int freshOrange = 0;
        int minutes = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) freshOrange++;
                if(grid[i][j] == 2) q.push({i, j});
            }
        }

        if(freshOrange == 0) return 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while(!q.empty()){
            int size = q.size();
            bool rotten = false;

            while(size--){
                auto [x, y] = q.front(); q.pop();

                for(int d = 0; d < 4; d++){
                    int nx = x + dr[d];
                    int ny = y + dc[d];

                    if(nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == 1){
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                        freshOrange--;
                        rotten = true;
                    }
                }
            }

            if(rotten) minutes++;
        }

        return (freshOrange == 0) ? minutes : -1;
    }
};
