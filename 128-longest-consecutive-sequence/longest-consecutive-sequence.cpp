class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int maxLen = 1;
    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void unite(int u, int v){
        int parU = find(u);
        int parV= find(v);
        if(parU == parV) return;

        if(rank[parU] < rank[parV]){
            swap(parU, parV);
        }
        parent[parV] = parU;
        rank[parU] += rank[parV];
        maxLen = max(maxLen, rank[parU]);
    }
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        parent.resize(n);
        rank.assign(n, 1);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
        unordered_map<int, int> m; //maps value to its first seen index
        for(int i = 0; i < n; i++){
            if(m.count(nums[i])) continue; //ignores duplicates
            m[nums[i]] = i;
            if(m.count(nums[i] - 1)){
                unite(i, m[nums[i] - 1]);
            }
            if(m.count(nums[i] + 1)){
                unite(i, m[nums[i] + 1]);
            }
        }
        return maxLen;
    }
};