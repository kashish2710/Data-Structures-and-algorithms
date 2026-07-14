class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
       int earn=accumulate(gas.begin(),gas.end(),0);
       int spend=accumulate(cost.begin(),cost.end(),0);
       if(spend>earn)return -1;
        int total=0;
        int result=0;
        for(int i=0;i<gas.size();i++){
            total+=gas[i]-cost[i];
            if(total<0){
                result=i+1;
                total=0;
            }
        }
        return result;
    }
};
