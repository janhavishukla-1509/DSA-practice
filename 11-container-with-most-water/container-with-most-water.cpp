class Solution {
public:
    int maxArea(vector<int>& height) {
        int lp = 0, rp = height.size()-1;
        int maxwater = 0; int area;
        int w = 0, ht = 0;
        while(lp < rp)
        {
            w = rp - lp;
            ht = min(height[lp],height[rp]);
            area = w * ht;
            maxwater = max(maxwater, area);
            height[lp] < height[rp] ? lp ++ : rp --;
        }
        return maxwater;
        
    }
};