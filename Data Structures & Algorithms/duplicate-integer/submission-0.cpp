class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int, int> hashmap;
        for(int i = 0; i < nums.size(); i++){
            if(hashmap.find(nums[i]) != hashmap.end()){
                return true;
            }
            hashmap.insert(pair<int, int>(nums[i], 1));
        }
        return false;
    }
};