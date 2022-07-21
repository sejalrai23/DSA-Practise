class Solution {
public:
    
    vector<char> v={'a','b','c'};
    
    void helper(vector<string> &ans,string t,int n,char prev)
    {
        if(n==0)
        {  
            cout<<t<<endl;
            ans.push_back(t);
            
            return ;
        }
        
        for(int i=0;i<v.size();i++)
        {
            if(prev!=v[i])
            {
                t.push_back(v[i]);
                helper(ans,t,n-1,v[i]);
                t.pop_back();
            }
        }
    }
    
    string getHappyString(int n, int k) {
        
        vector<string> ans;
        string t="";
        helper(ans,t,n,'#');
        
        if(ans.size()<k)
        {
            return "";
        }
        return ans[k-1];
    }
};