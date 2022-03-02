class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans=0;
        map<string,int> m;
        for(auto it :words){
            m[it]++;
        }
        for(auto it : m){
            int i=0,cnt=0;
            for(int j=0;j<s.length() && i<it.first.length();j++){
                if(s[j]==it.first[i]){
                    cnt++;
                    i++;
                }else{
                    continue;
                }
            }
            if(it.first.length()==cnt){
                
                ans+=it.second;
            }
        }
        return ans;
        
    }
};

// TC= O(N) == O(5000) + O(5000)*O(50) == O(10^4) == O(N)
//SC=O(5000)