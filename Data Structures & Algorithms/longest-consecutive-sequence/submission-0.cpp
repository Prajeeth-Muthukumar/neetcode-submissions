class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        sort(nums.begin(), nums.end());

        int res = 1;
        int temp = 1;
        for(int i = 0; i < nums.size()-1; i++){
            if((nums[i+1]-nums[i]) == 1){
                temp++;
                res = max(res, temp);
            }
            else if((nums[i+1]-nums[i]) == 0) continue;
            else temp = 1;
        }
        return res;
    }
};
