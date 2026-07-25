class Solution {
public:
    bool isOpen(char c1, char c2){
        if(c1 == '(' && c2 == ')') return true;
        if(c1 == '{' && c2 == '}') return true;
        if(c1 == '[' && c2 == ']') return true;
        else return false;
    }
    bool isValid(string s) {
        stack<int> stk;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') stk.push(s[i]);
            else{
                if(!stk.empty() && isOpen(stk.top(), s[i])) stk.pop();
                else return false;
            }
        }
        return stk.empty();
    }
};