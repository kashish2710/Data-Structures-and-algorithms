class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        int i=0;
        int j=n-1;
        int area=0;
        while(i<j){
int width=j-i;
area=max(area,min(heights[i],heights[j]) * width);
if(heights[i]<heights[j]){
    i++;
}
else j--;
        }
        return area;
    }
};
