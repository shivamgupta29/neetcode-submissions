class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int num:nums){
            freq[num]++;
        }
        int n = nums.size()/2;
        for(auto [num, f] : freq){
            if(f > n){
                return num;
            }
        }
        return -1;
    }
};