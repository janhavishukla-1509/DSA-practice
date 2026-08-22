class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int st = 0; 
        int sum = 0;
        int currsum = nums[0] + nums[1] + nums[2];
        for(int st = 0; st < n - 2; st ++){
            int j = st + 1;
            int end = n - 1;
            while(j < end){ 
            sum = nums[st] + nums[j] + nums[end];
            if(sum == target)
            return sum;
            if(abs(target - sum) < abs(target - currsum))
            currsum = sum;
            if(sum > target)
            end --;
            else
            j ++;
            }
        }
        return currsum;
    }
};