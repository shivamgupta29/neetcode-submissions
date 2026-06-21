class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int num:nums){
            if(freq[num] == 1){
                return true;
            }
            freq[num]++;
        }
        return false;
    }
};