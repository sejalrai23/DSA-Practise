class Solution 
{
public:
    
    bool has_operator(string s,int start,int end)
    {
        for(int i=start;i<=end;i++)
        {
            if(s[i]=='+' || s[i]=='-' || s[i]=='*')
            {
                return true;
            }
        }
        return false;
    }
  
    vector<int> helper(string &s,int start,int end)
    {
     
        if(!has_operator(s,start,end))
        {
            return {stoi(s.substr(start,end+1))};
        }
     
        vector<int>ans;
        for(int i=start;i<=end;i++)
        {
            if(s[i]=='+' || s[i]=='-' || s[i]=='*')
            {   
                vector<int>first=helper(s,start,i-1);
                vector<int>second=helper(s,i+1,end);
                for(auto x:first)
                {
                    for(auto y:second)
                    {
                        int res;
                        if(s[i]=='+')
                        {
                            res=x+y;
                        }
                        else if(s[i]=='-')
                        {
                            res=x-y;
                        }
                        else if(s[i]=='*')
                        {
                            res=x*y;
                        }
                        ans.push_back(res);
                    }
                }
            }
        }
        return ans;
    }
    vector<int> diffWaysToCompute(string expression) 
    {
        return helper(expression,0,expression.length()-1);
    }
};  