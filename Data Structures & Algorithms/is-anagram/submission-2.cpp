class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        vector<int> alphabet1(26,0);
        vector<int> alphabet2(26, 0);
        for(int i = 0; i < s.length(); i++){
            alphabet1[s[i]-'a']++;
            alphabet2[t[i]-'a']++;
        }

        if(alphabet1 == alphabet2){
            return true;
        }
        return false;
    }
};
