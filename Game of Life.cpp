class Solution {
public:
    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, 1}, {-1, -1}, {1, -1}, {1, 1}};

    bool isValid(int i, int j, int m, int n){
        if(i > m-1 || j > n-1 || i < 0 || j < 0) return false;
        return true;
    }

    void gameOfLife(vector<vector<int>>& board) {
        int m = (int)board.size(), n = (int)board[0].size();
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                int count = 0;
                for(auto &[dx, dy] : dir){
                    int x = i+dx;
                    int y = j+dy;
                    if(isValid(x, y, m, n)) count += (board[x][y] == 1) || (board[x][y] == 2);
                }
                if(board[i][j] == 1 && (count < 2 || count > 3)) board[i][j] = 2;
                else if(board[i][j] == 0 && count == 3) board[i][j] = -1;
            }
        }
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(board[i][j] == 2) board[i][j] = 0;
                else if(board[i][j] == -1) board[i][j] = 1;
            }
        }
    }
};
