class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for(string str: strs){
            res = res+to_string(str.length())+"#"+str;
        }
        return res;
    }

    vector<string> decode(string s) {
        string size;
        vector<string> res;
        int i = 0;
        while(i < s.length()){
            while(s[i] != '#'){
                size += s[i];
                i++;
            }
            i++;
            res.push_back(s.substr(i, stoi(size)));
            i += stoi(size);
            size = "";
        }
        return res;
    }
};
