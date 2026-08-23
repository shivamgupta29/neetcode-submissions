/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> startTime;
        vector<int> endTime;
        for(auto [start, end]: intervals){
            startTime.push_back(start);
            endTime.push_back(end);
        }
        sort(startTime.begin(), startTime.end());
        sort(endTime.begin(), endTime.end());

        int i=0;
        int j=0;
        int ans=0;
        int rooms=0;
        while(i<intervals.size() && j<intervals.size()){
            if(startTime[i] < endTime[j]){
                rooms++;
                i++;
            }else{
                rooms--;
                j++;
            }
            ans = max(ans, rooms);
        }
        return ans;
    }
};
