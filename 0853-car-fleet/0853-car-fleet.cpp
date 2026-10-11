class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int, int> store;
        for(int i=0; i<position.size(); i++){
            store[position[i]] = speed[i];
        }

        int fleet = 0;
        double maxTime = 0;
        
        for (auto it = store.rbegin(); it != store.rend(); it++) {
            double time_needed = (double)(target - it->first) / it->second;
            if (time_needed > maxTime) {
                fleet++;
                maxTime = time_needed;
            }
        }
        return fleet;
    }
};