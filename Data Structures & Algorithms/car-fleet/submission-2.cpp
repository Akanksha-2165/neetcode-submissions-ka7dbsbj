class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        double fleetTime=0;
        int fleets=0;

        vector<pair<int, int>> cars;
        for(int i=0; i< speed.size(); i++)  
            cars.push_back({position[i], speed[i]});
        sort(cars.begin(), cars.end());

        for(int i=position.size()-1; i>=0; i--)    {
            double time= (double)(target - cars[i].first)/cars[i].second;
            if(fleetTime < time)   {
                fleetTime=time;
                fleets ++;
            }
        }
        return fleets;
    }
};
//STACK 
/*stack<double> fleetTime;
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
*/
//BRUTE
// Compute the arrival time for every car.
// For each car, compare it with every car ahead to determine
// whether it catches up before the destination.
// Merge fleets manually by simulating these interactions.
//Time: O(n²)            Space: O(1)

//OPTIMAL (Stack) ✅
// Cars can only interact with cars ahead of them, so first sort
// the cars by position.
// Compute each car's time to reach the target.
// Traverse from the car closest to the target to the farthest.
// Maintain a stack of fleet arrival times.
// If the current car takes longer than the fleet ahead,
// it forms a new fleet (push its time).
// Otherwise, it catches that fleet and merges with it.
// The number of fleets equals the stack size.
//Time: O(n log n) (sorting dominates)    Space: O(n) (stack + car pairs)\

//OPTIMAL (Space Optimised) ⭐
// Sort cars by position and compute each car's arrival time.
// Traverse from the car closest to the target.
// Keep only the arrival time of the latest fleet.
// If the current car takes longer than the latest fleet,
// it forms a new fleet and updates the fleet time.
// Otherwise, it catches the fleet ahead.
// This removes the need for a stack.
//Time: O(n log n) (sorting)     Space: O(n) (car pairs, O(1) extra after sorting)

