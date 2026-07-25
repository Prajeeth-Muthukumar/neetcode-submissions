class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash(nums.size());
        for(int i = 0; i < nums.size(); i++){
            int diff = target-nums[i];
            if(hash.find(diff) != hash.end()){
                return {hash[diff], i};
            }
            hash[nums[i]] = i;
        }
    }
};
