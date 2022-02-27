class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long cnt=0;
        long long low=1 , high=100000000000001;
        while(low<=high){
             long long j=low+ (high-low)/2;
            long long trips=0;
            for(int t: time){
                trips+= j/t;
            }
            if(trips<totalTrips){
               
                low=j+1;
            }else{
                 cnt=j;
                high=j-1;
            }
            
            
        }
        return cnt;
    }
};