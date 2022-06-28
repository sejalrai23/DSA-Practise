class Solution {
public:
    int minDeletions(string s) {
       unordered_map<char,int> mp;
        for(auto it:s){
            mp[it]++;
        }
        priority_queue<pair<int , char>> pq;
        for(auto it: mp){
            // cout<<it.second<<"-"<<it.first<<endl;
            pq.push({it.second ,it.first });
        }
        int prev=pq.top().first;
        pq.pop();
        int ans=0;
        while(!pq.empty()){
               // cout<<pq.top().first<<"-"<<pq.top().second<<endl;
            int curr= pq.top().first;
            while(curr>=prev && prev>0){
                curr--;
                ans++;
            }
            if(prev==0) {
                ans+=curr;
                curr=0;
            }
            
            // cout<<prev<<"-"<<curr<<endl;
            prev=curr;
         
            pq.pop();
        }
        return ans;
    }
};