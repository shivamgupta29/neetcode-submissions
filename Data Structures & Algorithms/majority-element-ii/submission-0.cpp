class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> freq;
        for(int num:nums){
            freq[num]++;
        }
        vector<int> ans;
        for(auto [num, f]: freq){
            if(f > (n/3)){
                ans.push_back(num);
            }
        }
        if(ans.empty()) return {};
        return ans;
    }
};