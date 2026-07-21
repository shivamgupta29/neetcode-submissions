class Solution {
public:
    int ans;
    int N;
    vector<bool> col;
    vector<bool> diag1; // row - col + N - 1
    vector<bool> diag2; // row + col
    void solve(int row, vector<string>& board){
        if(row==N){
            ans++;
            return;
        }
        for(int j=0;j<N;j++){
            if (col[j] || diag1[row - j + N - 1] || diag2[row + j])
                continue;
            // Place 
            board[row][j] = 'Q';
            col[j] = true;
            diag1[row - j + N - 1] = true;
            diag2[row + j] = true;

            solve(row + 1, board);

            // Backtrack
            board[row][j] = '.';
            col[j] = false;
            diag1[row - j + N - 1] = false;
            diag2[row + j] = false;
        }
    }
    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        N=n;
        ans=0;
        col.assign(n, false);
        diag1.assign(2 * n - 1, false);
        diag2.assign(2 * n - 1, false);
        solve(0, board);
        return ans;
    }
};