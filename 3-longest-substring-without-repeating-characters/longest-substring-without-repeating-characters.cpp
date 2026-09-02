class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int len = 0;
        int maxlen = 0;
        unordered_map<char, int> m;
        int l = 0, r = 0;
        while(r < n){
            if(m.find(s[r]) != m.end()){
                l = max(m[s[r]] + 1, l);
            }
            len = r - l + 1;
            maxlen = max(len, maxlen);
            m[s[r]] = r;
            r ++;
        }
        return maxlen;
    }
};