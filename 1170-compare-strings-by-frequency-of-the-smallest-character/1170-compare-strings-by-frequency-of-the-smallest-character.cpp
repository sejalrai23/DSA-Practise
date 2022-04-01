class Solution {
public:
   
    int getCount(string &s ){
       sort(s.begin(),s.end());
       char ch=s[0];
        return count(s.begin(),s.end(),ch);
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> res;
        vector<int> vec;
        for(auto it:words){
            int c=getCount(it);
            res.push_back(c);
        }
        sort(res.begin(),res.end());
        for(auto it:queries ){
            int cnt=getCount(it);
            int ind=upper_bound(res.begin(),res.end(), cnt)-res.begin();
            int ans=res.size()-ind;
            // cout<<cnt<<"-"<<ans<<endl;
            vec.push_back(ans);
        }
        return vec;
        
    }
};