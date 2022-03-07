class Solution {
public:
    vector<int> prefix_calc(string s){
        int n=s.length();
        vector<int> pi (n,0);
        for(int i=1;i<n;i++){
            int j=pi[i-1];
            while(j>0 && s[i]!=s[j]){
                j=pi[j-1];
            }
            if(s[i]==s[j]){
                j++;
            }
            pi[i]=j;
        }
        return pi;
    }
    bool queryString(string s, int n) {
       vector<int> prefix=prefix_calc(s);
        const regex pattern("^0+(?!$)"); 
        for(int k=1;k<=n;k++){
            string res = bitset<8> (k).to_string();
            res = regex_replace(res, pattern, "");
            // cout<<res<<endl;
            int pos=-1;
            int i=0,j=0;
            while(i<s.length()){
                if(s[i]==res[j]){
                    i++;
                    j++;
                }
                else{
                    if(j!=0){
                        j=prefix[j-1];
                    }else{
                        i++;
                    }
                }
                if(j==res.length()){
                    pos=i-res.length();
                    break;
                }
            }
            if(pos==-1){
                return false;
            }
           
        }
        return true;
    }
};