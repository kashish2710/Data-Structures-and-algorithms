class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<long long>pq {gifts.begin(),gifts.end()};
        long long gift=0;
        while(k--){
            if(!pq.empty()){
                int max=pq.top();
                pq.pop();
                pq.push(floor(sqrt(max)));
            }
        }
        while(!pq.empty()){
            gift+=pq.top();
            pq.pop();
        }
        return gift;
    }
};