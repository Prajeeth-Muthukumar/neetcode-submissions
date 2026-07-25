class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> partition(string s) {
        vector<string> part;
        dfs(0, s, part);
        return res;
    }

    void dfs(int i, string& s, vector<string>& part){
        if(i >= s.size()){
            res.push_back(part);
            return;
        }

        for(int j = i; j < s.size(); j++){
            if(isPali(i, j, s)){
                part.push_back(s.substr(i, j-i+1));
                dfs(j+1, s, part);
                part.pop_back();
            }
        }
    }

    bool isPali(int i, int j, string& s){
        while(j > i){
            if(s[j] != s[i]) return false;
            j--;
            i++;
        }
        return true;
    }
};