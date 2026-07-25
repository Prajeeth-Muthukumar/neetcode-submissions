class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> n(nums.size()-1, 0);
        for(int i = 0; i < nums.size(); i++){
            if(n[nums[i]-1]) return nums[i];
            n[nums[i]-1]++;
        }
        return 0;
    }
};
