class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<long long, long long> mp;
        long long day =0;
        
        for(auto it : tasks){
            if(mp.find(it)!=mp.end()){
               int sp= day- mp[it];
                if(sp<space){
                    day+= space- sp;             
                }
            }
            day++;
            mp[it]=day;
        }
        return day;
    }
};