class Solution {
public:
    int longestPalindrome(vector<string>& words) {
       map<string , int> mp;
        int cntdiff=0 , cntsame=0, maxi=0;
        for(auto it :words){
          mp[it]++;
        }
        // cout<<mp.size()<<endl;
        int ans=0, flag=0;
         for(auto it : mp){
            string res=it.first;
            string find="";
            find+=res[1];
            find+=res[0];
            if(mp[find]>0){
                // cout<<res<<"-"<<find<<endl;
                if(res==find){
                   if(mp[res]%2==0){
                       ans+= mp[res]*2;
                   }else{
                       flag= 1;
                       ans+= (mp[res]-1)*2;
                   }
                    
                    
                }else{
                     ans+= min(mp[res], mp[find])*4;
                }
               
            } 
            mp[res]=0;
        }    
        
        // for (auto it: mp){
        //     cout<<it.first<<"-"<<it.second<<endl;
        // }
        if(flag) ans+=2;
        return ans;
    }
};