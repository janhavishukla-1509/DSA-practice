class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        int num = k;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i ++){
            if(nums[i] == num){
                i =0;
                num += k;
            }
        }
        return num;
    }
};