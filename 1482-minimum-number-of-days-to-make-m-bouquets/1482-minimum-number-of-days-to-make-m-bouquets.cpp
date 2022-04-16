class Solution {
public:
    bool isValid(vector<int>&bloom , int mid , int m , int k){
        int ans=0,cnt=0;
        for(int i=0;i<bloom.size();i++){
           if(bloom[i]<=mid){
               cnt++;
           }else{
               cnt=0;
           }
            if(cnt==k){
                ans++;
                cnt=0;
            }
            if(ans==m) return true;
        }
        return false;
    }
    int minDays(vector<int>& bloom, int m, int k) {
        int st= *min_element(bloom.begin(),bloom.end());
        int end= *max_element(bloom.begin(),bloom.end());
        int ans=-1;
        while(st<=end){
            int mid=st + (end-st)/2;
            // int mid1=*lower_bound(bloom.begin(),bloom.end(),mid);
            if(isValid(bloom,mid, m , k)){
                ans=mid;
                end=mid-1;
                
            }else{
               st=mid+1;
            }
            
        }
        return ans;
        
    }
};