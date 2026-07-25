class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty()) return "";
        int resLen = INT_MAX, rstart = -1;
        int l = 0;

        unordered_map<char, int> tcount;
        for(char c: t){
            tcount[c]++;
        }

        unordered_map<char, int> scount;
        int have = 0, need = tcount.size();
        for(int r = 0; r < s.length(); r++){
            scount[s[r]]++;

            if(tcount.count(s[r]) && tcount[s[r]] == scount[s[r]]){
                have++;
            }

            while(have == need){
                if((r-l+1) < resLen){
                    resLen = r-l+1;
                    rstart = l;
                }
                scount[s[l]]--;
                if(tcount.count(s[l]) && scount[s[l]] < tcount[s[l]]){
                    have--;
                }
                l++;
            }
        }
        return resLen == INT_MAX ? "":s.substr(rstart, resLen);
    }
};
