class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] > 0){
                    long long currSum = 0;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    currSum += grid[i][j];
                    grid[i][j] = 0;
                    while(!q.empty()){
                        auto [r, c] = q.front();
                        q.pop();
                        for(auto& d : dir){
                            int nr = r + d[0];
                            int nc = c + d[1];
                            if(nr >= 0 && nr < m && nc >= 0 &&nc < n && grid[nr][nc] > 0){
                                currSum += grid[nr][nc];
                                grid[nr][nc] = 0;
                                q.push({nr, nc});
                            }
                        }
                    }
                    if(currSum % k == 0){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};