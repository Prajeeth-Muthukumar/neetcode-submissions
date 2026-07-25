class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        res.clear();
        sort(candidates.begin(), candidates.end());
        vector<int> curr;
        backTrack(candidates, target, 0, curr, 0);
        return res;
    }

    void backTrack(const vector<int>& nums, int target, int i, vector<int>& curr, int sum){
        if(target == sum){
            res.push_back(curr);
            return;
        }

        for(int j = i; j < nums.size(); j++){
            if(j > i && nums[j] == nums[j-1]) continue;
            if(sum+nums[j] > target) break;
            curr.push_back(nums[j]);
            backTrack(nums, target, j+1, curr, sum+nums[j]);
            curr.pop_back();
        }
    }
};