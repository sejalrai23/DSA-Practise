class Solution {
public:
    string ans="";
   void dfs(map<string , int> &mp , int n ,int i, string res){
       if(ans!="") return ;
       if( res.length()==n || i==n){
           // cout<<res<<endl;
           if(mp[res]==0){
               ans=res;
               return;
               
           } 
           return;
       }
       res+='0';
       dfs(mp , n , i+1 , res);
       res.pop_back();
       res+='1';
       dfs(mp , n , i+1 , res);
       res.pop_back();
       
   }
    string findDifferentBinaryString(vector<string>& nums) {
        int n= nums[0].length();
       map<string , int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        // cout<<mp.size()<<endl;
        dfs(mp , n , 0 , "");
        return ans;
        
        
        
        
    }
};