class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> alpha(26, 0);
        for(char c: tasks) alpha[c-'A']++;

        sort(alpha.begin(), alpha.end());
        int maxf = alpha[25];
        int idle = (maxf-1)*n;

        for(int i = 24; i >= 0; i--){
            idle -= min(maxf-1, alpha[i]);
        }
        return max(0, idle)+tasks.size();
    }
};
