class Solution {
public:
    int findMin(vector<int> &nums) {
        int min = nums[0];
        for(int n: nums){
            if(min > n) min = n;
        }
        return min;
    }
};
