class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans="";
        stack<char> s;
        s.push(num[0]);
        ans+=num[0];
        if(k==num.size()){
            return "0";
        }
        for(int i=1;i<num.length();i++){
            while(!s.empty() && num[i] < s.top() && k){
                s.pop();
                k--;
                ans.pop_back();
               
            }
            s.push(num[i]);
            ans+=num[i];
            
        }
         int j=0;
        cout<<ans<<"-"<<k<<endl;
        if(k==0){
           while(ans[j]=='0'){
             j++;  
           }
           ans=ans.substr(j, ans.length()-j);
            
        } else{
            ans=ans.substr(0, ans.size()-k);
        }
        // if(ans.size()>k){
        //      return 
        //  }
        j=0;
        while(ans[j]=='0'){
             j++;  
         }
        ans=ans.substr(j, ans.length()-j);
         
         
        return ans=="" ? "0" : ans;
        
    }
};