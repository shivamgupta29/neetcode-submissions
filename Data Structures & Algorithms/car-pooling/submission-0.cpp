class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pickup;
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > drop;
        for (int i = 0; i < trips.size(); i++) {
            pickup.push({trips[i][1], i});
        }
        int passengers = 0;
        while (!pickup.empty()) {
            auto [start, idx] = pickup.top();
            pickup.pop();
            while (!drop.empty() && drop.top().first <= start) {
                passengers -= drop.top().second;
                drop.pop();
            }
            passengers += trips[idx][0];

            if (passengers > capacity) {
                return false;
            }
            drop.push({trips[idx][2], trips[idx][0]});
        }

        return true;
    }
};