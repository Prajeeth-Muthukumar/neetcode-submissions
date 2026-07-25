class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_set<char> op = {'+', '-', '*', '/'};
        stack<int> numStack;

        for(auto s: tokens){
            if(op.count(s[0]) && s.length() == 1){
                int num1 = numStack.top();
                numStack.pop();
                int num2 = numStack.top();
                numStack.pop();
                int res;
                if(s == "+") res = num1+num2;
                if(s == "-") res = num2-num1;
                if(s == "*") res = num1*num2;
                if(s == "/") res = num2/num1;
                numStack.push(res);
            }
            else numStack.push(stoi(s));
        }
        return numStack.top();
    }
};
