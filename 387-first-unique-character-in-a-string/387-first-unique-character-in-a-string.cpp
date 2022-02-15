class Solution {
public:
//     int firstUniqChar(string s) {
//         unordered_map<char,int > m;
//         for(int i=0;i<s.length();i++){
//             m[s[i]]++;
//         }
//         for(auto it:m){
//             cout<<it.first <<"-"<<it.second<<endl;
//         }
        
//         return 0;
//     }
    int firstUniqChar(string s) {
        unordered_map<char, pair<int,int>> m;
        int idx=0;
        for (int i = 0; i < s.size(); i++) {
            m[s[i]].first++;
            m[s[i]].second=i;
        }
        int ans=INT_MAX;
        for(auto i:m){
            if(i.second.first==1){
                ans=min(ans,i.second.second);
            }
            // cout<<i.first <<"-"<<i.second.first <<"-"<<i.second.second<<endl;
        }
        return ans==INT_MAX ? -1 : ans;
    }

};