class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backTrack(0, {}, 0, candidates, target);
        return res;
    }

    void backTrack(int i, vector<int> curr, int sum, vector<int>& nums, int target){
        if(target == sum){
            res.push_back(curr);
            return;
        }

        for(int j = i; j < nums.size(); j++){
            if(nums[j]+sum > target){
                return;
            }
            curr.push_back(nums[j]);
            backTrack(j, curr, sum+nums[j], nums, target);
            curr.pop_back();
        }
    }
};