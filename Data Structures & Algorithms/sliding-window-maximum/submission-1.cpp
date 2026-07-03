class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.size() < k){
            int maxi = INT_MIN;
            for(int i=0;i<nums.size();i++){
                maxi = max(maxi, nums[i]);
            }
            return {maxi};
        }
        vector<int> ans;
        for(int i=0;i<nums.size()-k+1;i++){
            int l = i;
            int j = l+k-1;
            int maxi = INT_MIN;
            while(l<=j){
                maxi = max(maxi, nums[l]);
                l++;
            }
            ans.push_back(maxi);
        }
        return ans;
    }
};
