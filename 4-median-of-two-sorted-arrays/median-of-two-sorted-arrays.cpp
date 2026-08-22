class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        nums1.resize(m + n);
        int idx = m + n -1;
        int i = m -1;
        int j = n -1;
        while(i >= 0 && j >= 0){
            if(nums1[i] >= nums2[j]){
                nums1[idx] = nums1[i];
                idx --;
                i --;
            }
            else{
                nums1[idx] = nums2[j];
                idx --;
                j --;
            }
        }
        while(j >= 0){
            nums1[idx--] = nums2[j--];
        }
        
        if((m + n) % 2 != 0){
            return nums1[(m + n) / 2];
        }
        else{
            return (nums1[(m + n) / 2 - 1] + nums1[(m + n) / 2]) / 2.0;
        }
    }
};