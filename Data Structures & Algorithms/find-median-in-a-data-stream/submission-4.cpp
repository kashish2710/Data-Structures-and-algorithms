class MedianFinder {
public:
priority_queue<int>maxheap;
priority_queue<int,vector<int>,greater<int>>minheap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
       if(maxheap.empty() || num <= maxheap.top() ) {
        maxheap.push(num);    
       }
       else{
        minheap.push(num);
       }
        if(maxheap.size()>minheap.size()+1){
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        else if(minheap.size()>maxheap.size()){
            maxheap.push(minheap.top());
            minheap.pop();
          
       }
    
    }
    
    double findMedian() {
     if(minheap.size()==maxheap.size()){
return (maxheap.top()/2.0)+(minheap.top()/2.0);
     }
     else
return (double)maxheap.top();
     
    }
};
