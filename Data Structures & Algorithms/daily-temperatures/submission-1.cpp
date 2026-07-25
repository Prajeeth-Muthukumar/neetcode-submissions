class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
       int n = temperatures.size();
       stack<int> tempInd;
       vector<int> res(n, 0);

        for(int i = 0; i < n; i++){
            while(!tempInd.empty() && temperatures[tempInd.top()] < temperatures[i]){
                int j = tempInd.top();
                tempInd.pop();
                res[j] = i-j;
            }
            tempInd.push(i);
        }
       return res;
    }
};
