class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n=heights.size();
        vector<int>ans(n,0);
        stack<int>st;
        st.push(heights[n-1]);
        for(int i=n-2;i>=0;i--){
            int count=0;
           while(st.size()>0 && st.top()<heights[i]){
                st.pop();
                count++;
            }
            if(st.size()>0)count++;
            st.push(heights[i]);
            ans[i]=count;

        }
        return ans;
    }
};