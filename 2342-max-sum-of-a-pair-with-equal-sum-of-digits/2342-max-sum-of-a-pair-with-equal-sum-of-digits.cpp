class Solution {
public:
    int getsum(int num){
        string s= to_string(num);
        int ans=0;
        for(int i=0;i<s.length();i++){
            // cout<<s[i]<<endl;
            ans+= s[i]-'0';
        }
        return ans;
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