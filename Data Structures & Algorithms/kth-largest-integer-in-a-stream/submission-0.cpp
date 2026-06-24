class KthLargest {
public:
    int K;
    priority_queue<int, vector<int>, greater<int>> heap;
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(int num:nums){
            add(num);
        }
    }
    
    int add(int val) {
        heap.push(val);
        if(heap.size() > K){
            heap.pop();
        }
        return heap.top();
    }
};
