class Solution {
public:
    bool check(vector<vector<char>> &board, int row, int col, char c) {
        for (int k = 0; k < 9; k++) {
            if (board[k][col] == c)
                return false;

            if (board[row][k] == c)
                return false;

            if (board[(3 * (row / 3)) + (k / 3)][3 * (col / 3) + (k % 3)] == c)
                return false;
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    char c = board[i][j];
                    board[i][j] = '.';

                    if (!check(board, i, j, c)) {
                        return false;
                    }

                    board[i][j] = c; 
                }
            }
        }
        return true;
    }
};