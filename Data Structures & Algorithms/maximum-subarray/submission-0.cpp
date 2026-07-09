class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int local=nums[0];
        int maxi=nums[0];
        for(int i=1;i<nums.size();i++){
            local = max(nums[i], nums[i]+local);
            if(local > maxi){
                maxi = local;
            }
        }
        return maxi;
    }
};
