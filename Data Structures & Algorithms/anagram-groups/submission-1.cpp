class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        map<vector<int>, vector<string>> hashmap;
        for(string s: strs){
            vector<int> alpha(26, 0);
            for(char c: s){
                alpha[c-'a']++;
            }
            hashmap[alpha].push_back(s);
        }

        for(auto i: hashmap){
            res.push_back(i.second);
        }
        return res;
    }
};
