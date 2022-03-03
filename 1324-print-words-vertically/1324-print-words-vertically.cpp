class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> v;
        stringstream ss(s);
        string word;
        int maxi=0;
        while(ss>>word){
            v.push_back(word);
            int k=word.length();
            maxi= max(maxi,k);
        }
        vector<string> ans;
        for(int i=0;i<maxi ;i++){
            int idx=i;
            string t="";
            for(int j=0;j<v.size();j++){
                // if(idx>v[j].length()){
                //     v[j]+="";
                // }
                // t+=v[j][idx];
                idx>=v[j].length() ? t+=" " : t+=v[j][idx];
               
            }
             auto p = t.find_last_not_of(" \t");
             if (string::npos != p) t.erase(p+1);
            ans.push_back(t);
        }
        return ans;
    }
};