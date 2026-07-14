class Solution {
public:

int count_set_bits(int num){
    int count=0;
    while(num){
    num=num & (num-1);
    count++;
    }
    return count;

}
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0;i<=n;i++){
            int bit=count_set_bits(i);
            ans.push_back(bit);
        }
        return ans;
    }
};
