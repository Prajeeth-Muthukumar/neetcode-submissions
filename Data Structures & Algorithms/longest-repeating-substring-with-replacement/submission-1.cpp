class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        int maxf = 0, l = 0;

        vector<int> count(26, 0);
        for(int r = 0; r < s.length(); r++){
            int num = s[r]-'A';
            count[num]++;
            maxf = max(count[num], maxf);

            if((r-l+1)-maxf > k){
                count[s[l]-'A']--;
                l++;
            }
            res = max(res, r-l+1);
        }
        return res;
    }
};
