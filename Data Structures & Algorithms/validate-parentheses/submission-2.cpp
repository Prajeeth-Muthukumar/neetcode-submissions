class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;
        unordered_map<char, char> close = {{')','('},{'}','{'}, {']', '['}};
        
        for(char c: s){
            if(close.count(c)){
                if(brackets.empty() || brackets.top() != close[c]){
                    return false;
                }
                brackets.pop();
            }
            else brackets.push(c);
        }

        return brackets.empty();
    }
};
