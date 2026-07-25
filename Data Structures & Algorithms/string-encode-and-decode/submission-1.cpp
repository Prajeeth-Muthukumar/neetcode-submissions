class Solution {
public:
    string encode(vector<string>& strs) {
        string res = "";
        for(string& s: strs) res += to_string(s.size())+"#"+s;
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while(i < s.size()){
            int size;
            int temp = i;
            while(s[temp] != '#') temp++;
            size = stoi(s.substr(i, temp));
            i = temp+1;
            res.push_back(s.substr(i, size));
            i += size;
        }
        return res;
    }
};
