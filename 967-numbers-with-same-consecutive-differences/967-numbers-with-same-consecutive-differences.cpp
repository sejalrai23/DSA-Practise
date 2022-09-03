class Solution {
    
    vector<int> ans;
    
    void Solve(int len , int &k , string  num, int digit)
    {
        if(len == 0 )
        {
                ans.push_back(stoi(num));
           return ;
        }
        for(int i = 0 ; i<10 ; i++)
        {
            if(abs(i-digit) == k)
                Solve(len-1 , k, num+ to_string(i), i);
        }
    }
    
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        for(int i = 1 ; i<=9 ; i++)
        {
             Solve(n-1 , k, to_string(i), i);
        }
        
        return ans;
    }
};