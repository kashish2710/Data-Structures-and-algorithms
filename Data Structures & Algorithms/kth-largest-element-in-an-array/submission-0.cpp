class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq(nums.begin(),nums.end());
        while(k){
            int num=pq.top();
            pq.pop();
            k--;
            if(k==0){
                return num;
            }
        }
        return -1;
    }
};
