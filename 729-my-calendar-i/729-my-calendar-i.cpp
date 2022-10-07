class MyCalendar {
   map<int, int> mp;
public:    
    bool book(int start, int end) {
        mp[start]++;    //is start then increase counter because it can overlap
        mp[end]--;      //if end decrease because it cannot overlap anymore
        int ans=0, temp=0;
        for(auto it: mp){
            temp+=it.second;
            ans=max(ans , temp);   // calculate max for every step
            if(ans==2){
                mp[start]--;
                mp[end]++;
                return false;
            }
            
            
        }
        // cout<<ans<<endl;
   
        return true;
    }
};
/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */