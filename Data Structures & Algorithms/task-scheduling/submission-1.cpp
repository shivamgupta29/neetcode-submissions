class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for (char c : tasks) {
            freq[c]++;
        }
        priority_queue<pair<int, char>> heap;
        for (auto [c, f] : freq) {
            heap.push({f, c});
        }
        int maxFreq = heap.top().first;
        int maxCount = 0;
        while (!heap.empty() && heap.top().first == maxFreq) {
            maxCount++;
            heap.pop();
        }
        int skeleton = (maxFreq - 1) * (n + 1) + maxCount;
        int remaining = 0;
        while (!heap.empty()) {
            remaining += heap.top().first;
            heap.pop();
        }
        int slots = skeleton - maxFreq * maxCount;
        if (remaining <= slots) {
            return skeleton;
        }
        return skeleton + (remaining - slots);
    }
};