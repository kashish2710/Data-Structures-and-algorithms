class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
       int n2=nums2.size();
       unordered_map<int,int>mpp;
       stack<int>st;
        for(int i=n2-1;i>=0;i--){
          
            while(!st.empty() && st.top()<nums2[i]){
                st.pop();
            }
              if(st.empty()){
                st.push(nums2[i]);
                mpp[nums2[i]]=-1;
            }
            if(st.top()>nums2[i]){
                mpp[nums2[i]]=st.top();
                st.push(nums2[i]);
            }
        }
vector<int>ans;
for(int i=0;i<nums1.size();i++){
    ans.push_back(mpp[nums1[i]]);
}
        
        return ans;




    }
};