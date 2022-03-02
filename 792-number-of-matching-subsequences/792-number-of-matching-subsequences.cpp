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
            // cout<<it<<"-"<<cnt<<endl;
            if(it.first.length()==cnt){
                
                ans+=it.second;
            }
        }
        return ans;
        
    }
};