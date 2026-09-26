class Solution {
public:
    bool isPalin(string s1){
        string s2 = s1;
        reverse(s1.begin(), s1.end());
        return s1 == s2;
    }
    void getPalin(string s, vector<string> &partition, vector<vector<string>> &ans){
        if(s.size() == 0){
            ans.push_back(partition);
            return;
        }
        for(int i = 0; i < s.size(); i++){
            string part = s.substr(0, i + 1);
            if(isPalin(part)){
                partition.push_back(part);
                getPalin(s.substr(i + 1), partition, ans);
                partition.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s){
        vector<vector<string>> ans;
        vector<string> partition;
        getPalin(s, partition, ans);
        return ans;
    }
};