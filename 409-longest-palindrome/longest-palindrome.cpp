class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> freq(128, 0);
        for(char ch : s){
            freq[ch]++;
        }
        int len = 0;
        bool hasOdd = false;
        for(int count : freq){
            len += count/2 * 2;
            if(count % 2 == 1){
                hasOdd = true;
            }
        }
        return hasOdd ? len + 1 : len;
    }
};