class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashmap;
        vector<int> result(2);
        for(int i = 0; i < nums.size(); i++){
            hashmap[nums[i]] = i;
        }

        for(int i = 0; i < nums.size(); i++){
            if(hashmap.count(target-nums[i]) && (hashmap[target-nums[i]] != i)){
                result[0] = i;
                result[1] = hashmap[target-nums[i]];
                return result;
            }
        }
    }
};
