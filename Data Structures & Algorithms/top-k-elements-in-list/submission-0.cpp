class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(int num:nums){
            freq[num]++;
        }
        vector<vector<int>> buckets(nums.size()+1);
        for(auto &p:freq){
            buckets[p.second].push_back(p.first);
        }
        vector<int> res;
        for(int i=buckets.size()-1;i>=0;i--){
            for(int n:buckets[i]){
                res.push_back(n);
                if(res.size()==k){
                    return res;
                }
            }
        }
        return res;
    }
};
