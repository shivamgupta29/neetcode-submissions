class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_set<int> seen;
        vector<int> ans(nums.size());
        int j=0;
        for(int i=0;i<nums.size();i++){
            if(!seen.count(nums[i])){
                seen.insert(nums[i]);
                ans[j] = nums[i];
                j++;
            }
        }  
        for(int i=0;i<nums.size();i++){
            nums[i] = ans[i];
        } 
        return j;
    }
};