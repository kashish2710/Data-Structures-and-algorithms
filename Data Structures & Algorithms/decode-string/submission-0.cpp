class Solution {
public:
    string decodeString(string s) {
      stack<string>result;
      stack<int>count;
      int num=0;
      string curr="";
      for(char ch:s){
        if(isdigit(ch)){
            num=num*10+(ch-'0');
        }
        else if(ch=='['){
            result.push(curr);
            count.push(num);
            num=0;
            curr="";
        }
        else if(ch==']'){
            string temp=result.top();
            result.pop();
            int time=count.top();
            count.pop();
            while(time--)temp+=curr;
            curr=temp;
        }
        else {
            curr+=ch;
        }
      }  
      return curr;
    }
};