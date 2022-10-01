class Solution {
public:
    string frequencySort(string s) {
        map<char , int> mp;
        priority_queue<pair<int , char>> pq;
        
        for(auto it:s){
            mp[it]++;
        }
        
        for(auto it: mp){
            pq.push({it.second , it.first});
        }
        
        string ans="";
        while(!pq.empty()){
            int num= pq.top().first;
            char x= pq.top().second;
            pq.pop();
            ans+=string(num , x);
        }
        return ans;
    }
};