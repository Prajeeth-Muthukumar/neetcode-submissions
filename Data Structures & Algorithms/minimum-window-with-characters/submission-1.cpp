class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty()) return "";
        unordered_map<char, int> window, countT;

        for(char c: t) countT[c]++;
        int l = 0, have = 0, need = countT.size();
        int res = INT_MAX, start = 0;
        for(int r = 0; r < s.size(); r++){
            window[s[r]]++;
            if(countT.count(s[r]) && window[s[r]] == countT[s[r]]) have++;

            while(have == need){
                window[s[l]]--;
                if((r-l+1) < res){
                    res = r-l+1;
                    start = l;
                }

                if(countT.count(s[l]) && window[s[l]] < countT[s[l]]) have--;
                l++;
            }
        }
        return (res == INT_MAX)? "":s.substr(start, res);
    }
};