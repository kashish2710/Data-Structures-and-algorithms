class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mpp;
        for(char task:tasks){
            mpp[task]++;
        }
        priority_queue<int>pq;
        for(auto it:mpp){
            pq.push(it.second);
        }
        int time=0;
        while(!pq.empty()){
            vector<int>temp;
            for(int i=0;i<n+1;i++){
               if(!pq.empty()){   int freq=pq.top();
                freq--;
                pq.pop();
                temp.push_back(freq);
            }
            }
            for(int &f:temp){
             if(f>0)  pq.push(f);
            }
             if(!pq.empty())time+=n+1;
             else time+=temp.size();
        }
       return time;
    }
};
