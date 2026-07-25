class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;

        vector<int> count1(26, 0);
        vector<int> count2(26, 0);

        for(int i = 0; i < s1.length(); i++){
            count1[s1[i]-'a']++;
            count2[s2[i]-'a']++;
        }

        int match = 0;
        for(int i = 0; i < 26; i++){
            if(count1[i] == count2[i]) match++;
        }

        int l = 0;
        for(int r = s1.length(); r < s2.length(); r++){
            if(match == 26) return true;

            int index = s2[r]-'a';
            count2[index]++;
            if(count1[index] == count2[index]){
                match++;
            }
            else if(count1[index]+1 == count2[index]){
                match--;
            }

            index = s2[l]-'a';
            count2[index]--;
            if(count1[index] == count2[index]){
                match++;
            }
            else if(count1[index]-1 == count2[index]){
                match--;
            }
            l++;
        }
        return match == 26;
    }
};
