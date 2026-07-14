class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>maxleft(n,height[0]);
      
   
        for(int i=1;i<n;i++){
            maxleft[i]=max(height[i],maxleft[i-1]);
        }
         vector<int>maxright(n,height[n-1]);
 
        for(int i=n-2;i>=0;i--){
            maxright[i]=max(height[i],maxright[i+1]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
        int maxheight=min(maxleft[i],maxright[i]);

        ans+=maxheight-height[i];
        
           
        }
        return ans;


    }
};
