class Solution {
public:
 
    int minCost(string colors, vector<int>& time) {
        int cnt=0;
        for(int i=0;i<colors.length();i++){
            int j=i+1;
            int mini=time[i];
            int sum=time[i];
            // cout<<sum<<"-"<<mini<<"-"<<i<<"-"<<j<<endl;
            while(colors[j]==colors[i]){
                mini=max(mini , time[j]);
                sum+=time[j];
                j++;
            }
            // cout<<sum<<"-"<<mini<<endl;
            cnt+=(sum-mini);
            i=j-1;
        }
        return cnt;
    }
}; 