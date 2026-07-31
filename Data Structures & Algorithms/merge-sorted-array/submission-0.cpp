class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp(m+n);
        int it1 = 0;
        int it2 = 0;
        int i=0;
        while(it1<m && it2<n){
            if(nums1[it1] >= nums2[it2]){
                temp[i] = nums2[it2];
                it2++;
            }else{
                temp[i] = nums1[it1];
                it1++;
            }
            i++;
        }
        while(it1<m){
            temp[i] = nums1[it1];
            it1++;
            i++;
        }
        while(it2<n){
            temp[i] = nums2[it2];
            it2++;
            i++;
        }
        for(int i=0;i<m+n;i++){
            nums1[i] = temp[i];
        }
    }
};