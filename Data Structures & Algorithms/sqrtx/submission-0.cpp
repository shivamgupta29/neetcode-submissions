class Solution {
public:
    int mySqrt(int x) {
        if(x<2) return x;
        int l=1;
        int h=x/2;
        int res=1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if((long long)mid*mid <= x){
                res = mid;
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
        return res;
    }
};