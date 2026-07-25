class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> numList;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int num: nums){
            numList.push(num);
            if(numList.size() > k) numList.pop();
        }
    }
    
    int add(int val) {
        numList.push(val);
        if(numList.size() > k) numList.pop();
        return numList.top();
    }
};
