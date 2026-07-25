class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> hashmap;

        for(string& s: strs){
            string word = s;
            sort(s.begin(), s.end());

            if(hashmap.find(s) != hashmap.end()){
                hashmap[s].push_back(word);
            }
            else{
                hashmap.insert(pair<string, vector<string>>(s, {word}));
            }
        }
        for(auto ele: hashmap){
            result.push_back(ele.second);
        }
        return result;
    }
};
