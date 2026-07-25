class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> temp;
        int n = temperatures.size();
        vector<int> res(n, 0);

        for(int i = 0; i < temperatures.size(); i++){
            while(!temp.empty() && temperatures[temp.top()] < temperatures[i]){
                int j = temp.top();
                res[j] = i-j;
                temp.pop();
            }
            temp.push(i);
        }

        return res;
    }
};
