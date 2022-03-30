class Solution {
public:
    int binarySearch(vector<int>& weights , int w, int days){
        int cnt=1;
        int sum=0;
        for(int i=0;i<weights.size();i++){
            sum+=weights[i];
            if(sum>w){
                cnt++;
                sum=weights[i];
            }
            
        }
        return cnt;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int high=0, low=INT_MIN;
        for(int i=0;i<weights.size();i++){
            low=max(low,weights[i]);
            high+=weights[i];
        }
        int ans=0;
        while(low<=high){
            int mid = low + (high-low)/2;
            int cnt= binarySearch(weights,mid, days);
            // cout<<mid<<"-"<<cnt<<endl;
            if(cnt<=days){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
        
    }
};