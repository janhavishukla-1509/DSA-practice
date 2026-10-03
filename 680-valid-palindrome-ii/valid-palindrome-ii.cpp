class Solution {
public:
    bool isPalin(const string &s, int left, int right){
        while(left < right){
            if(s[left] != s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        while(left < right){
            if(s[left] != s[right]){
                return isPalin(s, left + 1, right) || isPalin(s, left, right - 1);
            }
            left++;
            right--;
        }
        return true;
    }
};