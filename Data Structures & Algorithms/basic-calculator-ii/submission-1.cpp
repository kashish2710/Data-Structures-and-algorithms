class Solution {
public:
    int calculate(string s) {
        stack<int>st;
        int n=s.size();
        char op='+';
        int num=0;
        for(int i=0;i<=n;i++){
            char ch;
            if(i==n){
                ch='-';
            }
            else ch=s[i];
            if(isdigit(ch)){
                num=num*10+(ch-'0');
            }
            else if(ch!=' '){
                if(op=='+'){
                    st.push(num);

                }
                else if(op=='-'){
                    st.push(-num);
                    
                }
                 else if(op=='*'){
                    int val=st.top();
                    st.pop();
                    st.push(val*num);
                    
                }
                 else if(op=='/'){
                    int val=st.top();
                    st.pop();
                    st.push(val/num);
                    
                }
                op=ch;
                num=0;
            }
        }
        int ans=0;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};