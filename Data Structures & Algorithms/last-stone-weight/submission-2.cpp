class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if (stones.empty()) return 0;
        priority_queue<int> heap;
        for(int i=0;i<stones.size();i++){
            heap.push(stones[i]);
        }
        while(heap.size() > 1){
            int f=heap.top();
            heap.pop();
            int s=heap.top();
            heap.pop();
            int n = abs(f-s);
            heap.push(n);
            
        }
        return heap.top();
    }
};
