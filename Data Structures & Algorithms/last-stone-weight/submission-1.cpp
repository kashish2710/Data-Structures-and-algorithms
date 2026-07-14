class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq(stones.begin(),stones.end());
        while(!pq.empty()){
           if(pq.size()==1)return pq.top();
            int stone1=pq.top();
            pq.pop();
            int stone2=pq.top();
            pq.pop();
           int remain=stone1-stone2;
        
            if(remain>0)pq.push(remain);
            
      
        }
        return 0;

    }
};
