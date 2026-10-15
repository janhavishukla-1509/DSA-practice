class Solution {
public:
    void dfs(vector<vector<int>>& img, int i, int j, int newColor, int orgColor){
        int m = img.size();
        int n = img[0].size();
        if(i < 0 || j < 0 || i >= m || j >= n || img[i][j] == newColor || img[i][j] != orgColor){
            return;
        }
        img[i][j] = newColor;
        dfs(img, i - 1, j, newColor, orgColor);
        dfs(img, i, j - 1, newColor, orgColor);
        dfs(img, i, j + 1, newColor, orgColor);
        dfs(img, i + 1, j, newColor, orgColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& img, int sr, int sc, int color) {
        dfs(img, sr, sc, color, img[sr][sc]);
        return img;
    }
};