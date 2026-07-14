class LRUCache {
public:
list<int>dll;
map<int, pair< list<int>::iterator , int >>mpp;
  int n;
    LRUCache(int capacity) {
      n=capacity;
    }
    void makerecent(int key){
          dll.erase(mpp[key].first);
        dll.push_front(key);
       
        mpp[key].first=dll.begin();
       
    }
    int get(int key) {
        if(mpp.find(key)==mpp.end()){
            return -1;
        }
        makerecent(key);
        return mpp[key].second;

        
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            makerecent(key);
            mpp[key].second=value;
        }
        else{
            dll.push_front(key);
            mpp[key]={dll.begin(),value};
            n--;
            }
            if(n<0){
                int key_to_be_del=dll.back();
                mpp.erase(key_to_be_del);
                dll.pop_back();
                n++;
            
        }
        
        
    }
};
