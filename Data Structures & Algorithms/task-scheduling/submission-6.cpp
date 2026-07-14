class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mpp;
        for(char ch:tasks){
            mpp[ch]++;
        }
        priority_queue<int>pq;
        for(auto it:mpp){
            pq.push(it.second);
        }
        //most freq upar hoga
        int time=0;
while(!pq.empty()){
    vector<int>temp;
    for(int i=0;i<n+1;i++){
        if(!pq.empty()){
            int freq=pq.top();
            pq.pop();
            freq--;
            temp.push_back(freq);
        }
    }
        for(int &f:temp){
            if(f>0)pq.push(f);
        }
        if(!pq.empty()){
            time+=n+1;
        }
        else{
            time+=temp.size();
        
    } 
}
return time;
    }
};
