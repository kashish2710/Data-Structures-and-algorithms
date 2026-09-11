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
            vector<int>freq;
           
           for(int i=0;i<n+1;i++){
           if(!pq.empty()){   int f=pq.top();
            pq.pop();
            f--;
            freq.push_back(f);
           }
            }
            for(int &f:freq){
                if(f>0)pq.push(f);
            }
            if(pq.empty()){
                time+=freq.size();
            }
            else {
                time+=n+1;
            }
        }
        return time;
    }
};
