class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n;
        int count1 = 1;
        int count2 = 2;
        for(int i = 3; i <= n; i ++){
            int curr = count1 + count2;
            count1 = count2;
            count2 = curr;
        }
        return count2;
    }
};