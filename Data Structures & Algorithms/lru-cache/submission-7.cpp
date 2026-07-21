class LRUCache {
public:
map<int,pair<list<int>::iterator,int>>mpp;
int n;
list<int>dll;

    LRUCache(int capacity) {
        n=capacity;
    }
    void makerecent(int key){
       dll.erase(mpp[key].first);
      dll.push_front(key);
      mpp[key].first=dll.begin();
    }
    int get(int key) {
        if(mpp.find(key)!=mpp.end()){
          makerecent(key);
          return mpp[key].second;
        }
        return -1;
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
         if(n<0){
          int keydelete=dll.back();
          dll.pop_back();
          mpp.erase(keydelete);
          n++;
         }
        }
      
    }
};
