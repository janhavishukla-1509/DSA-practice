class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int total = 0;
        bool hasNonZero = false;
        for(int x : nums){
            total ^= x;
            if(x != 0){
                hasNonZero = true;
            }
        }
        if(total != 0){
            return nums.size();
        }
        if(!hasNonZero){ //all elements are 0
            return 0;
        }
        return nums.size() - 1;
    }
};