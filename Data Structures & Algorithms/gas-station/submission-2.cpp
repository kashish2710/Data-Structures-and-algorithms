class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int ex=0;
        for(int num:cost){
          ex+=num;
        }
        int in=0;
        for(int num:gas){
          in+=num;
        }
        if(in<ex)return -1;
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
