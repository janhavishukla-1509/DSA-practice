class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int idx = 0;
        if(n == 0) return 0; //empty
        for(int i = 0; i < n; i ++){
            if(nums[i] != val){
                nums[idx] = nums[i];
            idx++;
            }
            
        }
        return idx;
    }
};