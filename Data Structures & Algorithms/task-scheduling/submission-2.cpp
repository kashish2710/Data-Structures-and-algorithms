class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mp;
        int time=0;
        for(int task:tasks){
            mp[task]++;
        }
        priority_queue<int>pq;
        for(auto it:mp){
            pq.push(it.second);
        }
        while(!pq.empty()){
            vector<int>temp;
            for(int i=0;i<n+1;i++){
              if(!pq.empty())  
          {    int freq=pq.top();
          pq.pop();
                freq--;
                temp.push_back(freq);}
            }
        
        for(int& f:temp){
            if(f>0)pq.push(f);
        }
        if(pq.empty()){
            time+=temp.size();

        }
        else{
            time+=n+1;
        }
        }
return time;
    }
};
