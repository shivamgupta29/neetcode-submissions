class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;

        priority_queue<pair<long long, pair<int, int>>> heap;

        for (auto& point : points) {
            int x = point[0];
            int y = point[1];

            long long dis = 1LL * x * x + 1LL * y * y;

            heap.push({dis, {x, y}});

            if (heap.size() > k) {
                heap.pop();
            }
        }

        while (!heap.empty()) {
            auto top = heap.top();
            heap.pop();

            int x = top.second.first;
            int y = top.second.second;

            ans.push_back({x, y});
        }

        return ans;
    }
};