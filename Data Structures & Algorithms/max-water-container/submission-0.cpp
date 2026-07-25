class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size()-1;
        int res = 0;

        while(l < r){
            int cap = min(height[l], height[r])*(r-l);
            res = max(res, cap);

            if(height[l] <= height[r]) l++;
            else r--;
        }
        return res;
    }
};
