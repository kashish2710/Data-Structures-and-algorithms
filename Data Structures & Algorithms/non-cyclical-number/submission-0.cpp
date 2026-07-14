class Solution {
public:
    set<int>myset;
    bool isHappy(int n) {
        if(n==1)return true;
     string num=to_string(n);
     int new_num=0;
     for(char ch:num){
         new_num+=(ch-'0')*(ch-'0');
     }   
            
    if(myset.find(new_num)!=myset.end())return false;
     myset.insert(new_num);
     return isHappy(new_num);
    }
};
