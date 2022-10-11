class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int, int> m1;
        for(auto x:nums){
            m1[x]++;
        }
        int cnt=0;
        
        
        for(auto x:m1){
           int t=k-x.first;
            if(t==x.first) cnt+= x.second /2;
            else if(m1[t]>0){
                int ans= min(x.second, m1[t]);
                m1[x.first]=x.second-ans;
                m1[t]-=ans;
                cnt+=ans;
            }
        }
        return cnt;
        
    }
};