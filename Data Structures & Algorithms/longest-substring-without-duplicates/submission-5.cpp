class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int res = 0, size = 0;
        unordered_set<int> letters;
        for(int r = 0; r < s.length(); r++){
            while(letters.find(s[r]) != letters.end()){
                letters.erase(s[l]);
                l++;
            }
            letters.insert(s[r]);
            res = max(res, r-l+1);
        }
        return res;
    }
};
