class Solution {
public:
    int lengthOfLastWord(string s) {
        reverse(s.begin(), s.end());
        int i = 0;
        int count = 0;
        int n = s.length();
        while (i < n && s[i] == ' ') {
            i++;
        }
        while(i < n && s[i] != ' '){
            count ++;
            i ++;
        }
        return count;
    }
};