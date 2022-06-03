class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans=0, cum=0, sum=0;
       for(int i=0;i<arr.size();i++){
           cum+=i;
           sum+=arr[i];
           if(sum==cum){
               ans++;
           }
       }
       return ans;
    }
};