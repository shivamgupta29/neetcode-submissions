class Solution {
public:
    int calculateDays(vector<int>& weights, int capacity){
        int day=1;
        int cap=0;
        for(int w:weights){
            if(cap+w<=capacity){
                cap += w;
            }else{
                day++;
                cap=w;
            }
        }
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int ans=0;
        int l=*max_element(weights.begin(), weights.end());
        int h=0;
        for(int w:weights){
            h += w;
        }
        while(l<=h){
            int mid=l+(h-l)/2;
            int daysTaken = calculateDays(weights, mid);
            if(daysTaken <= days){
                ans = mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};