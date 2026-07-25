class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int l = 0, r = matrix.size();
        while(l < r){
            int m = l+(r-l)/2;
            if(target < matrix[m][0]) r = m;
            else l = m+1;
        }

        int i = (l > 0 && matrix[l-1][n-1] >= target)? l-1:-1;
        if(i == -1) return false;
        l = 0, r = n;
        while(l < r){
            int m = l+(r-l)/2;
            if(target < matrix[i][m]) r = m;
            else l = m+1;
        }
        return (l > 0 && matrix[i][l-1] == target);
    }
};
