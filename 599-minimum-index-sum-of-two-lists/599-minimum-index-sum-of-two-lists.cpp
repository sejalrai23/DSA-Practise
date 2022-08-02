class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string , int> m;
        priority_queue<pair<int , string> , vector<pair<int , string>> , greater<pair<int, string>>> pq;
        for(int i=0;i<list1.size(); i++){
            m[list1[i]]=i;
        }
        
        for(int i=0;i<list2.size(); i++){
            if(m.find(list2[i])!=m.end()){
                m[list2[i]]+=i;
                pq.push({ m[list2[i]] , list2[i]});
            }else{
                m.erase(list2[i]);
            }
            
        }
        int mini=pq.top().first;
        vector<string> ans;
        // cout<<mini<<endl;
        while(!pq.empty() && pq.top().first==mini ){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
    
        return ans;
    }
};