class LRUCache {
public:
int n;
list<int>dll;
map<int,pair<list<int>::iterator,int>>mpp;

    LRUCache(int capacity) {
         n=capacity;
    }

void makeRecent(int key){
  dll.erase(mpp[key].first);//address 
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
        if(mpp.find(key)==mpp.end()){
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
        else{

          makeRecent(key);
          mpp[key].second=value;
        }
    }
};
