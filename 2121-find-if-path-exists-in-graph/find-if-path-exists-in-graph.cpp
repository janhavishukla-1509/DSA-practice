class Solution {


    // void dfs(int node, int destination, vector<vector<int>> &adj, vector<bool> &vis, bool &found){
    //     if(node == destination){ found = true;
    //     return;
    //     }
    //     vis[node] = true;
    //     for(int neigh : adj[node]){
    //         if(!vis[neigh] && !found){
    //             dfs(neigh, destination, adj, vis, found);
    //         }
    //     }
    // }
    // bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    //     vector<bool> vis(n, false);
    //     vector<vector<int>> adj(n);
    //     if(source == destination) return true;
    //     for(const auto& edge : edges){
    //         adj[edge[0]].push_back(edge[1]);
    //         adj[edge[1]].push_back(edge[0]);
    //     }
    //     bool found = false;
    //     dfs(source, destination, adj, vis, found);
    //     return found;
    // }

    //UNION-FIND APPROACH
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void unite(int u, int v){
        int parU = find(u); //0 rank[0] = 1 ; 3 ; 3 rank[3] = 1 ; 3
        int parV = find(v); //2 rank[2] = 0 ; 5 ; 4 rank[4] = 0 ; 3
        if(parU == parV) return;

        //Union By Rank
        if(rank[parU] < rank[parV]){
            parent[parU] = parV;
        }
        else if(rank[parU] > rank[parV]){
            parent[parV] = parU; //parent[2] = 0 ; parent[4] = 3
        }
        else{
            parent[parV] = parU; //0 became parent of 1 ; 3 bcms par of 5
            rank[parU]++; //rank[0] = 1 ; rank[3] = 1
        }
    }
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination){
        if(source == destination) return true;
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
        for(const auto &edge : edges){
            unite(edge[0], edge[1]);
        }
        return find(source) == find(destination); //parent[0] = 0, parent[5] = 3
    }
};