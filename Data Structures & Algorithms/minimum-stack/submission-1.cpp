class MinStack {
public:
    stack<int> stk;
    MinStack() {}
    
    void push(int val){
        stk.push(val);
    }
    
    void pop() {
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        stack<int> tmp;
        int m = stk.top();
        while(stk.size()){
            tmp.push(stk.top());
            m = min(m, stk.top());
            stk.pop();
        }

        while(tmp.size()){
            stk.push(tmp.top());
            tmp.pop();
        }

        return m;
    }
};
