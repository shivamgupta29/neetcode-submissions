class Solution {
public:
    vector<vector<string>> ans;
    int N;
    bool isSafe(int i, int j, vector<string> &board){
        //Up
        for(int row=i-1;row>=0;row--){
            if(board[row][j]=='Q') return false;
        }
        //DiagLUp
        for (int row = i - 1, col = j - 1; row >= 0 && col >= 0; row--, col--) {
            if (board[row][col] == 'Q')
                return false;   
        }
        //DiagRUp
        for (int row = i - 1, col = j + 1; row >= 0 && col < N; row--, col++) {
            if (board[row][col] == 'Q')
                return false;   
        }
        return true;
    }
    void solve(int i, vector<string>& board){
        if(i==N){
            ans.push_back(board);
            return;
        }
        for(int j=0;j<N;j++){
            if(isSafe(i, j, board)){
                board[i][j] = 'Q';
                solve(i+1, board);
                board[i][j] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        N=n;
        solve(0, board);
        return ans;
    }
};
