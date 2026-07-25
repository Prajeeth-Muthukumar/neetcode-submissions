class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int res = 0;
        vector<int> pre(n);
        vector<int> suc(n);

        pre[0] = height[0];
        for(int i = 1; i < n; i++){
            pre[i] = max(pre[i-1], height[i]);
        }

        suc[n-1] = height[n-1];
        for(int j = n-2; j >= 0; j--){
            suc[j] = max(suc[j+1], height[j]);
        }

        for(int i = 0; i < n; i++){
            res += min(pre[i], suc[i])-height[i];
        }
        return res;
    }
};
