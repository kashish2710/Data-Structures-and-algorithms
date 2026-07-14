class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string>mystack;
        if(tokens.size()==1)return stoi(tokens[0]);
        for(string token: tokens){
            if(token!="+" && token!="-" && token!="*" && token!="/"){
                mystack.push(token);
            }
            else{
                int op2=stoi(mystack.top());
                mystack.pop();
                int op1=stoi(mystack.top());
                mystack.pop();
                if(token=="+"){
                    mystack.push(to_string(op1+op2));
                }
                else if(token=="-"){
                      mystack.push(to_string(op1-op2));
                }
                else if(token=="*"){
                      mystack.push(to_string(op1*op2));
                }
                else{
                   if(op2) mystack.push(to_string(op1/op2));
                }

            }
        }
        return stoi(mystack.top());
    }
};
