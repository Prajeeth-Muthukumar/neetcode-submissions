class Solution {
public:
    vector<string> charMap = {"", "", "abc", "def", "ghi", "jlk", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        if(!digits.size()) return {};
        vector<string> res;
        string s = "";
        dfs(0, digits, s, res);
        return res;
    }

    void dfs(int i, const string& digits, string curr, vector<string>& res){
        if(i >= digits.size()){
            res.push_back(curr);
            return;
        }

        string charStr = charMap[digits[i]-'0'];
        for(char c: charStr){
            dfs(i+1, digits, curr+c, res);
        }
    }
};