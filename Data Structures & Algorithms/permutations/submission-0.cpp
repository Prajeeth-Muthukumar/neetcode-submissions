class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> perm = {{}};
        for(int n: nums){
            vector<vector<int>> new_perms;
            for(const auto& p: perm){
                for(int i = 0; i <= p.size(); i++){
                    vector<int> temp = p;
                    temp.insert(temp.begin()+i, n);
                    new_perms.push_back(temp);
                }
            }
            perm = new_perms;
        }
        return perm;
    }
};
