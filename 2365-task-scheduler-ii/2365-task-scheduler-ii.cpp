class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<long long, long long> mp;
        long long day =0;
        
        for(auto it : tasks){
            if(mp.find(it)==mp.end()){
                day++;
                mp[it]=day;
            }else{
                int sp= day- mp[it];
                if(sp<space){
                    day+= space- sp+1;
                    mp[it]=day;
                }else{
                    day++;
                    mp[it]=day;
                }
            }
        }
        return day;
    }
};