class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans;
        multiset<int> m{0};
        
        vector<pair<int, int>> points;
        
        for(auto b: buildings){
            points.push_back({b[0], -b[2]});
            points.push_back({b[1], b[2]});
        }
        
        sort(points.begin(), points.end());
        
        int curr = 0;
        
        for(int i = 0; i < points.size(); i++){
            int curP = points[i].first;
            int hP= points[i].second;
            
            if(hP < 0){
                m.insert(-hP);
            } else {
                m.erase(m.find(hP));
            }
            
            auto mTop = *m.rbegin();
            if(curr != mTop){
                curr = mTop;
                ans.push_back({curP, curr});
            }
        }
        
        return ans;
    }
};