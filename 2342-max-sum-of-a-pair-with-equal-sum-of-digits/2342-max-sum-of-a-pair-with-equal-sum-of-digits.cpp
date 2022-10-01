class Solution {
public:
    int getsum(int a){
        int sum=0;
       while (a != 0) {
            sum = sum + a % 10;
             a = a / 10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int,vector<int>> ump;
        for(auto it:nums){
            int sum= getsum(it);
            // cout<<sum<<endl;
            ump[sum].push_back(it);
        }
        int maxi=INT_MIN;
        
        for(auto it:ump){
            if(it.second.size()>=2){
                int sum=0;
                sort(it.second.rbegin(), it.second.rend());
                sum= it.second[0]+ it.second[1];
                 maxi=max(maxi , sum);
            } 
           
        }
        
        
        return maxi==INT_MIN ? -1 : maxi;
    }
};