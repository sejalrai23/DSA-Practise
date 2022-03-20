class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        priority_queue<pair<int, int> > pq;
        for(auto it:m){
            pq.push(make_pair(it.second,it.first));
        }
        while(k){
            int res=pq.top().second;
            pq.pop();
            ans.push_back(res);   
            k--;
        }
        return ans;
    }
};