class TimeMap {
public:
    map<pair<string , int> , string> mp;
    map<string , vector<int> > mp2;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[{key , timestamp}]= value;
        mp2[key].push_back(timestamp);
    }
    
    string get(string key, int timestamp) {
        if(mp.find({key , timestamp})!=mp.end()){
            return mp[{key , timestamp}];
        }else if(mp2.find(key)!=mp2.end()){
             // sort(mp2[key].begin(), mp2[key].end());
            auto it=lower_bound(mp2[key].rbegin(), mp2[key].rend(), timestamp, greater<int>());
            if(it!=mp2[key].rend()){
                return mp[{key, *it}];
            }else{
                it--;
            }
            // cout<<*it<<endl;
            if(*it > timestamp) return "";

            return mp[{key , *it}];
            
        }
        
       
       return "";
        
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */