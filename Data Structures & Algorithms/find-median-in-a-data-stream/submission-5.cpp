class MedianFinder {
public:
priority_queue<int>left_maxheap;
priority_queue<int,vector<int>,greater<int>>right_minheap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left_maxheap.empty() || num<=left_maxheap.top()){
         left_maxheap.push(num);
        }
        else{
            right_minheap.push(num);
        }
     
        if(left_maxheap.size()>right_minheap.size()+1){
            right_minheap.push(left_maxheap.top());
            left_maxheap.pop();
        }
        else if(right_minheap.size()>left_maxheap.size()){
            left_maxheap.push(right_minheap.top());
            right_minheap.pop();
        }
    }
    
    double findMedian() {
    if(left_maxheap.size()==right_minheap.size()) return (left_maxheap.top()/2.0)+(right_minheap.top()/2.0);
    else 
return (double)left_maxheap.top();
    }
};
