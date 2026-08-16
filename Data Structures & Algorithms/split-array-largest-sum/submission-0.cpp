class Solution {
public:
    bool splitPossible(vector<int>& nums, long long highest, int k){
        int subs=1;
        long long cap=0;
        for(int num:nums){
            if(cap+num<=highest){
                cap += num;
            }else{
                subs++;
                cap=num;
            }
        }
        return subs<=k;
    }

    int splitArray(vector<int>& nums, int k) {
        if(k>nums.size()) return -1;
        long long l=*max_element(nums.begin(), nums.end());
        long long h=accumulate(nums.begin(), nums.end(), 0LL);
        int ans=-1;
        while(l<=h){
            long long mid=l+(h-l)/2;
            if(splitPossible(nums, mid, k)){
                ans = mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};