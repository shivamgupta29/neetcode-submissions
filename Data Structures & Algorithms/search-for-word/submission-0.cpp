class Solution {
public:
    bool found(int i, int j, vector<vector<char>>& board, string& word, int idx){
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size()) return false;
        
        if(board[i][j] != word[idx]) return false;
        
        if(idx == word.size()-1) return true;
        
        char temp = board[i][j];
        board[i][j] = '#';
        
        bool find = found(i+1, j, board, word, idx+1) ||
                    found(i-1, j, board, word, idx+1) ||
                    found(i, j+1, board, word, idx+1) ||
                    found(i, j-1, board, word, idx+1);
        
        board[i][j] = temp;
        return find;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(found(i, j, board, word, 0)){
                    return true;
                }
            }
        }
        return false;
    }
};