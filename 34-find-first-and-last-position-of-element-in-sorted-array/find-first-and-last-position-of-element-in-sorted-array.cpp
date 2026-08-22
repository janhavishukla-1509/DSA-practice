class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        
        int first = -1, last = -1;
            int st = 0;
            int end = n - 1;
        while(st <= end){
            int mid = st + (end - st)/2;

            if(nums[mid] == target){
                first = mid;
                end = mid - 1;
            }
            else if(nums[mid] > target){
                end = mid - 1;
            }
            else{
                st = mid + 1;
            }
        }
        st = 0; end = n - 1;
        while(st <= end){
            int mid = st + (end - st)/2;
            if (nums[mid] == target){
                last = mid;
                st = mid + 1;
            }
            else if (nums[mid] > target){
                end = mid - 1;
            }
            else{
                st = mid + 1;
            }
        }
        return {first, last};
    }
};