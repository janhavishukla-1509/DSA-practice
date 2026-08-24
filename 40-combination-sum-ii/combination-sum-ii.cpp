class Solution {
public:
set<vector<int>> s;
    void getAllComb(vector<int>& candidates, int target, int start, vector<int>& comb, vector<vector<int>>& ans){
        
        if(target == 0){
            ans.push_back(comb);
            return;
        }
        for(int i = start; i < candidates.size(); i++){
            if(candidates[i] > target){
                break;
            }
            if(i > start && candidates[i] == candidates[i - 1]){
                continue;
            }
        
        comb.push_back(candidates[i]);
        getAllComb(candidates, target - candidates[i], i + 1, comb, ans);
        comb.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> comb;
        vector<vector<int>> ans;
        getAllComb(candidates, target, 0, comb, ans);
        return ans;
    }
};