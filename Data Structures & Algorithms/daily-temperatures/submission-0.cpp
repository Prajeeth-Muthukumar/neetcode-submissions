class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                int diff = temperatures[j]-temperatures[i];
                if(diff > 0){
                    res[i] = j-i;
                    break;
                }
            }
        }
        return res;
    }
};
