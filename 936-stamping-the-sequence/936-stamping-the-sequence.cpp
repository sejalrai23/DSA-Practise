class Solution {
public:
   int stars, n, m;
    
    bool checkAndReplace(string& target, int& start, string& stamp){
        for(int i = 0; i < m; i++)
            if(target[i + start] != '*' && target[i + start] != stamp[i]) return false;
        ans.push_back(start);
        for(int i = start; i - start < m; i++) 	
            stars += (target[i] != '*'), target[i] = '*';        
        return true; 
    }
    
    vector<int> ans;     
    vector<int> movesToStamp(string stamp, string target) {
        stars = 0, n = size(target), m = size(stamp);        
        vector<bool> vis(n, false);  
        while(stars < n){           
            bool replaced = false;
            for(int i = 0; i <= n - m && stars < n; i++)
                if(!vis[i]) replaced = checkAndReplace(target, i, stamp), vis[i] = replaced;
            if(!replaced) return {};
        }            
        reverse(begin(ans), end(ans));
        return ans;
    }
};




