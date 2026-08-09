class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>st;
        for(string ch:operations){
            if(ch=="D"){
              int op1=st.top();
                
               
                st.push((2*op1));
  }
            
            else if(ch=="+"){
            int op1 = st.top();
st.pop();

int op2 = st.top();
st.pop();

st.push(op2);
st.push(op1);
st.push(op1 + op2);
                         
  }
  else if(ch=="C"){
    st.pop();
  }
  else{
    st.push(stoi(ch));
        }
}
        int ans=0;
        while(!st.empty()){
            ans=ans+st.top();
            st.pop();
        }
        return ans;
    }
};