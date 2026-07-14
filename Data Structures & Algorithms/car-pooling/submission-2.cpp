class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // Map stores: location -> net change in passengers
        map<int, int> timeline;
        
        for (const auto& trip : trips) {
            int passengers = trip[0];
            int startLocation = trip[1];
            int endLocation = trip[2];
            
            timeline[startLocation] += passengers; // Boarding
            timeline[endLocation] -= passengers;   // Alighting
        }
        
        int currentPassengers = 0;
        // Iterate through the sorted timeline
        for (const auto& [location, netChange] : timeline) {
            currentPassengers += netChange;
            if (currentPassengers > capacity) {
                return false;
            }
        }
        
        return true;
    }
};