class LRUCache {
public:
int n;
map<int,pair<list<int>::iterator,int>>mpp;
list<int>dll;
    LRUCache(int capacity) {
        n=capacity;

    }
    void makeRecent(int key){
      dll.erase(mpp[key].first);
        dll.push_front(key);
        mpp[key].first=dll.begin();
    }
    int get(int key) {
       if(mpp.find(key)!=mpp.end()){
        makeRecent(key);
        return mpp[key].second;
       } 
       return -1;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            mpp[key].second=value;
            makeRecent(key);
        }
        else{
            dll.push_front(key);
            mpp[key]={dll.begin(),value};
            n--;
            if(n<0){
                int key_delete=dll.back();
                dll.pop_back();
                mpp.erase(key_delete);
                n++;
            }
        }
    }
};
