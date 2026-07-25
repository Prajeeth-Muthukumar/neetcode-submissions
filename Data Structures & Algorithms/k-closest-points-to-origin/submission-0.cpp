class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int l = 0, r = points.size()-1;
        int pivot = points.size();

        while(pivot != k){
            pivot = partition(points, l, r);
            if(pivot < k) l = pivot+1;
            else r = pivot-1;
        }
        return vector<vector<int>>(points.begin(), points.begin()+k);
    }
    int euclidean(vector<int>& point) {
        return point[0] * point[0] + point[1] * point[1];
    }
    
    int partition(vector<vector<int>>& points, int l, int r){
        int pivotIdx = r;
        int pivotDist = euclidean(points[pivotIdx]);
        int i = l;
        for(int j = l; j < r; j++){
            if(euclidean(points[j]) <= pivotDist){
                swap(points[i], points[j]);
                i++;
            }
        }
        swap(points[i], points[r]);
        return i;
    }
};
