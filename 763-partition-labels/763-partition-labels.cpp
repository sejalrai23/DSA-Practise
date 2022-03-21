class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.size();
        vector<int> res;
        map<char,int> mp;
        for(int i=0;i<n;++i){
            mp[s[i]]=i+1;
        }
        int i=0;
        while(i<n){
            int temp=mp[s[i]],prev=i;
            while(i<n && temp-1!=i){
                temp=max(temp,mp[s[i]]);
                i++;
            }
            i++;
            res.push_back(temp-prev);
        }
        return res;
    }
};