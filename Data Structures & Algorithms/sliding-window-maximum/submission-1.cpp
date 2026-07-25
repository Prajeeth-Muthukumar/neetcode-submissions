class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> rightMax(n);
        vector<int> leftMax(n);
        vector<int> res(n-k+1);

        leftMax[0] = nums[0];
        rightMax[n-1] = nums[n-1];
        for(int i = 1; i < n; i++){
            if(i % k == 0) leftMax[i] = nums[i];
            else leftMax[i] = max(leftMax[i-1], nums[i]);

            if((n-i-1) % k == 0) rightMax[n-i-1] = nums[n-i-1];
            else rightMax[n-i-1] = max(rightMax[n-i], nums[n-i-1]);
        }

        for(int i = 0; i < n-k+1; i++) res[i] = max(rightMax[i], leftMax[i+k-1]);

        return res;
    }
};