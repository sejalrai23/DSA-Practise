class Solution {
public:
    int maxArea(int h, int w, vector<int>& hor, vector<int>& vert) {
        int mod=1e9+7;
        vert.push_back(w);
        vert.insert(vert.begin(), 0);
        hor.push_back(h);
        hor.insert(hor.begin(), 0);
        sort(vert.begin(), vert.end());
        sort(hor.begin(), hor.end());
        int maxiv=0 , maxih=0;
        for(int i=1;i<vert.size();i++){
            // cout<<vert[i]-vert[i-1]<<endl;
            maxiv=(max((vert[i]-vert[i-1])%mod, maxiv))%mod;
        }
        for(int i=1;i<hor.size();i++){
            maxih=(max((hor[i]-hor[i-1])%mod, maxih))%mod;
        }
        return (1LL*maxih*maxiv) % 1000000007;
    }
};