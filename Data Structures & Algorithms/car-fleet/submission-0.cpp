class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>> cars(position.size());
        for(int i=0;i<position.size();i++){
            cars[i] = {position[i], (double)(target-position[i])/speed[i]};
        }

        sort(cars.begin(), cars.end());
        
        stack<double> fleetTime;
        for(int i=position.size()-1;i>=0;i--){
            double currentCarTime=cars[i].second;
            if(fleetTime.empty() || currentCarTime>fleetTime.top()){
                fleetTime.push(currentCarTime);
            }
        }

        return fleetTime.size();
    }
};
