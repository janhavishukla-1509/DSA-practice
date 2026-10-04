class Solution {
public:
    bool isPalin(const string &s, int l, int r){
        while(l < r){
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        if(n <= 1) return s;
        for(int len = n; len >= 1; len--){
            for(int i = 0;i <= n - len; i++){
                if(isPalin(s, i, i + len - 1)){
                    return s.substr(i, len);
                }
            }
        }
        return "";
    }
};