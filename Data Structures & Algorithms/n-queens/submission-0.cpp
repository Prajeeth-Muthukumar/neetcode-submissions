class Solution {
    int col = 0, negDiag = 0, posDiag = 0;
    vector<vector<string>> res;
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        backTrack(0, n, board);
        return res;
    }

    void backTrack(int r, const int n, vector<string>& board){
        if(r == n){
            res.push_back(board);
            return;
        }

        for(int c = 0; c < n; c++){
            if((col & (1 << c)) || (posDiag & (1 << (r+c))) || (negDiag & (1 << (r-c+n)))) continue;

            col ^= (1 << c); posDiag ^= (1 << (r+c)); negDiag ^= (1 << (r-c+n));
            board[r][c] = 'Q';
            backTrack(r+1, n, board);
            col ^= (1<<c); posDiag ^= (1<<(r+c)); negDiag ^= (1<<(r-c+n));
            board[r][c] = '.';
        }
    }
};