class TimeMap {
public:
    map<string,map<int,string>>mp;
    vector<int>store;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp){
        //auto i=[timestamp,value];
        mp[key].insert({timestamp,value});
        store.emplace_back(timestamp);
    }
    
    string get(string key, int timestamp) {
        // for(auto i:mp[key]){
        //     cout<<i.first<<" "<<i.second<<"\n";
        // }
        auto t=mp[key].upper_bound(timestamp);
        return t==mp[key].begin()?"":prev(t)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
