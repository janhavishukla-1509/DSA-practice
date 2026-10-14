class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum > 9LL * num){
            return "";
        }
        string ans(num, '0');
        for(int i = 0; i < num; i++){
            int d = min(9, sum);
            ans[i] = '0' + d;
            sum -= d;
        }
        return ans;
    }
};