class Solution {
public:
    static bool cmp(pair<string , int>& a , pair<string , int>& b){
        if(a.second==b.second) return a.first<b.first;
        return a.second>b.second;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string , int> mp;
        for(auto it: words){
            mp[it]++;
        }
        vector<pair<string , int>> vec;
        for(auto it: mp){
            vec.push_back({it.first, it.second});
        }
        sort(vec.begin(), vec.end(), cmp);
        vector<string> ans;
        for(int i=0;i<k ;i++){
            ans.push_back(vec[i].first);
        }
        return ans;
    }
};