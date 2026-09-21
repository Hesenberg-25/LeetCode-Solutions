class Solution {
public:
    void dfs(int store, int row, int col, vector<vector<int>>& image, int color){
        int n=image.size();
        int m=image[0].size();

        if(row<0 || row>=n || col<0 || col>=m || image[row][col]!=store) return;
        image[row][col]=color;

        dfs(store, row-1, col, image, color);
        dfs(store, row+1, col, image, color);
        dfs(store, row, col-1, image, color);
        dfs(store, row, col+1, image, color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int store = image[sr][sc];
        if(store == color) return image;
        
        dfs(store, sr, sc, image, color);
        return image;
    }
};