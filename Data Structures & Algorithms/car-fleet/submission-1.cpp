class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<double> fleetTime;

        vector<pair<int, int>> cars;
        for(int i=0; i< speed.size(); i++)  
            cars.push_back({position[i], speed[i]});
        sort(cars.begin(), cars.end());

        for(int i=position.size()-1; i>=0; i--)    {
            double time= (double)(target - cars[i].first)/cars[i].second;
            if(fleetTime.empty() || fleetTime.top() < time)
                fleetTime.push(time);
        }
        return fleetTime.size();
    }
};
