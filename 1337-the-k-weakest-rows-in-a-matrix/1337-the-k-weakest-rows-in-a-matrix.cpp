class Solution {
public:
    
  int calculateSoldierCount(vector<int>& v) {
        int l=0; int h=v.size()-1;
        while(l<=h) {
            int mid=l+(h-l)/2;
            if(v[mid]==0) {
                h=mid-1;
            } else {
                l=mid+1;
            }
        }
        return l;
    }

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue <pair<int,int> > pq;
        for(int i=0;i<mat.size();i++){
           int cnt=calculateSoldierCount(mat[i]);
            pq.push(make_pair(cnt , i));
            if(pq.size()>k){
                // cout<<pq.top().first<<"-"<<pq.top().second<<endl;
                pq.pop();
            }
        }
        vector<int> ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};





