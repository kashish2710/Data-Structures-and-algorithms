class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
       string result = "";

    while(true){

        // sort manually (3 values only → cheap)
        vector<pair<int,char>> v = {
            {a,'a'}, {b,'b'}, {c,'c'}
        };

        sort(v.begin(), v.end(), greater<>());
         bool added=false;
         for(auto it:v){
            int count=it.first;
            char ch=it.second;
            if(count==0)continue;
            int len=result.size();
            if(len>=2 && result[len-1]==ch &&result[len-2]==ch){
              continue;
            }
            result+=ch;
            if(ch=='a')a--;
            else if(ch=='b')b--;
            else c--;
            added=true;
            break;
         }
         if(added==false)break;
    }
return result;
    }
};