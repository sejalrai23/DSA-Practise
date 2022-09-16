class Solution {
public:
    string result;
    
    void solve(const string& pattern, int idx, string& num, vector<bool>& vis) {
        
        if(idx == pattern.size()) {
            if(num.size() == pattern.size() + 1 && num < result) result = num;
            return;
        }
        
        if(idx == -1) {
            for(int i=1; i<=9; i++) {
                if(!vis[i]) {
                    vis[i] = true;
                    num += (i + '0');
                    solve(pattern, idx+1, num, vis);    
                    num.pop_back();
                    vis[i] = false;   
                }
            }
            return;
        }        

		int dgt = num.back() - '0';
        
		if(pattern[idx] == 'I') {
            for(int i=dgt+1; i<=9; i++) {
                if(!vis[i]) {
                    vis[i] = true;
                    num += (i + '0');
                    solve(pattern, idx+1, num, vis);
                    num.pop_back();
                    vis[i] = false;
                }
            }
        }
        else {
            for(int i=dgt-1; i>=1; i--) {
                if(!vis[i]) {
                    vis[i] = true;
                    num += (i + '0');
                    solve(pattern, idx+1, num, vis);
                    num.pop_back();
                    vis[i] = false;
                }
            }
        }            
    }
    
    string smallestNumber(string pattern) {
        result = "987654321";
        string num = "";
        
        vector<bool> vis(10, false);
        
        solve(pattern, -1, num, vis);
        
        return result;
    }
};
