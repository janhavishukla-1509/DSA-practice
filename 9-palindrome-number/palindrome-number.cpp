class Solution {
public:
int reverse(int x) {
        int dig = 0, rev = 0;
        while(x != 0){
            dig = x % 10;
            if(rev > INT_MAX/10 || rev < INT_MIN/10)
            return 0;
            rev = (rev * 10) + dig;
            x /= 10;
        }
        return rev;
    }
    bool isPalindrome(int x) {
        if(x < 0)
        return false;
        int revNum = reverse(x);
        return x == revNum;
    }
};