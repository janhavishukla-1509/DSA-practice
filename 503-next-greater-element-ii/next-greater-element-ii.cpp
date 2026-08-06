class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        vector<int> ans(nums.size(), -1);
        int n = nums.size();
        for(int i = 2 * n - 1; i >= 0; i --){
            while(s.size() > 0 && s.top() <= nums[i % n]){
                s.pop();
            }
            if(s.empty()){
                ans[i % n] = -1;
            }
            else{
                ans[i % n] = s.top();
            }
            s.push(nums[i % n]);
        }
        return ans;
    }
};