class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int>pq;
        unordered_map<char,int>mpp;
        for(char ch:tasks){
            mpp[ch]++;
        }
        for(auto it:mpp){
           pq.push(it.second);
        }
        int time=0;
while(!pq.empty()){
    vector<int>temp;
    for(int i=0;i<=n;i++){
       if(!pq.empty()){  int num=pq.top();
         pq.pop();
         num--;
         temp.push_back(num);
       }
    }
    for(int &num:temp){
      if(num>0)  pq.push(num);
    }
    if(pq.empty())time+=temp.size();
else time+=n+1;
}

return time;


    }
};
