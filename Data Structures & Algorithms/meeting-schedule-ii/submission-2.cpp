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
        for(auto it:intervals){
              mpp[it.start]++;
              mpp[it.end]--;
        }
        int maxi=0;
        int sum=0;
        for(auto it:mpp){
            sum=sum+it.second;
            maxi=max(maxi,sum);
        }
        return maxi;
    }
};
