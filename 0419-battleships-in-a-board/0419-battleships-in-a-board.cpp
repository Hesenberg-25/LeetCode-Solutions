class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& board){

        int n = board.size();
        int m = board[0].size();

        if(row<0 || row>=n || col<0 || col>=m || board[row][col]!='X') return;

        board[row][col]='.';

        dfs(row-1, col, board);
        dfs(row+1, col, board);
        dfs(row, col-1, board);
        dfs(row, col+1, board);
    }
    int countBattleships(vector<vector<char>>& board) {
        
        int n = board.size();
        int m = board[0].size();
        int cnt = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]=='X'){
                    cnt++;
                    dfs(i, j, board);
                }
            }
        }

        return cnt;
    }
};