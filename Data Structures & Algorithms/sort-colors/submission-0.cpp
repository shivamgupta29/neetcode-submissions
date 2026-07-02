class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> freq(3, 0);
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        int i=0;
        int j=0;
        while(i<3){
            while(freq[i] != 0){
                nums[j] = i;
                j++;
                freq[i]--;
            }
            i++;
        }
    }
};