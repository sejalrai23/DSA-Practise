class Solution {
public:
    bool dfs(vector<int>& arr , int idx){
        if(idx<0 || idx>= arr.size()|| arr[idx]==-1 ) return false;
        if(arr[idx]==0) return true;
        int val=arr[idx];
        arr[idx]=-1;
        bool ans= dfs(arr , idx+val);
        arr[idx]=val;
        bool ans2= dfs(arr , idx-val);
        return ans || ans2;
    }
    bool canReach(vector<int>& arr, int start) {
        return dfs(arr, start);
    }
};