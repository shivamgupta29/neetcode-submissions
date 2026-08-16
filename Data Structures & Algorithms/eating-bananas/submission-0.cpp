class Solution {
public:
    int hoursTaken(vector<int>& piles, int speed){
        int hour=0;
        for(int pile: piles){
            hour += (pile+speed-1)/speed;
        }
        return hour;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int j=*max_element(piles.begin(), piles.end());
        int i=1;
        int ans=1;
        while(i<=j){
            int speed = i+(j-i)/2;
            int hours = hoursTaken(piles, speed);
            if(hours <= h){
                ans = speed;
                j=speed-1;
            }else{
                i=speed+1;  
            }
        }
        return ans;
    }
};
