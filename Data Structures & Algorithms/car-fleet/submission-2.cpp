class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        vector<pair<int,int>> cars;

        for(int i = 0; i < position.size(); i++) {
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.begin(), cars.end(), greater<pair<int,int>>());

        double prevtime = 0;
        int fleets = 0;

        for(auto &it : cars) {

            double currtime =
                (double)(target - it.first) / it.second;

            if(currtime > prevtime) {
                fleets++;
                prevtime = currtime;
            }
        }

        return fleets;
    }
};
