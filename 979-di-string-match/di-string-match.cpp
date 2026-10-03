class Solution {
public:
    vector<int> diStringMatch(string s) {
        int low = 0;
        int n = s.size();
        int high = n;
        vector<int> perm;
        for(char ch : s){
            if(ch == 'I'){
                perm.push_back(low++);
            }
            else{
                perm.push_back(high--);
            }
        }
        perm.push_back(low);
        return perm;
    }
};