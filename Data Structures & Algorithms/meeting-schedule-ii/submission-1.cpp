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
        map<int,int>mpp;
        for(int i=0;i<intervals.size();i++){
            mpp[intervals[i].start]++;//event started
            mpp[intervals[i].end]--;//event ended
        }
        int maxi=0;
        int curr=0;
        for(auto it:mpp){
            curr=curr+it.second;
            maxi=max(maxi,curr);
        }
return maxi;
    }
};
