class Solution {
public:

    void dfs(int i, vector<vector<int>> &adj, vector<bool> &vis){
        vis[i] = true;
        for(int j = 0; j < adj[i].size(); j++){
            if(adj[i][j] == 1 && !vis[j]){
                dfs(j, adj, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& adj) {
        int prov = 0;
        int n = adj.size(); //nxn
        vector<bool> vis(n, false);
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i, adj, vis);
                prov++;
            }
        }
        return prov;
    }
};