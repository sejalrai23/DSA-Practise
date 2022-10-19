class Solution {
public:
   
    
    class cmp{
    public:
    bool operator()(pair<string, int> a, pair<string, int> b) const{
       if(a.second==b.second) return a.first < b.first;
    
        return a.second > b.second;
    }
};
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string , int> mp;
        for(auto it: words){
            mp[it]++;
        }
        priority_queue<pair<string , int> , vector<pair<string , int>> , cmp> pq;
        for(auto it: mp){
            pq.push(make_pair(it.first , it.second));
            if(pq.size()>k) pq.pop();
        }
        vector<string> ans(k ,"");
       while(!pq.empty()){
           ans[k-1]= pq.top().first;
           k--;
           pq.pop();
       }
        return ans;
    }
};