class Solution {
public:
    int findMin(vector<int> &nums) {
        int l=0;
        int h=nums.size()-1;
        int ans=INT_MAX;
        while(l<=h){
            if(nums[l] < nums[h]){
                ans = min(ans, nums[l]);
                break;
            }
            int mid=(l+h)/2;
            ans = min(ans, nums[mid]);
            if(nums[mid] >= nums[l]){
                l = mid+1;
            }else{
                h = mid-1;
            }
        }
        return ans;
    }
};
