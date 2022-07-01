class Solution {
public:
    static bool cmp(vector<int> a , vector<int> b){
        if(a[1]==b[1]) return a[0]<b[0];
        return a[1]> b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int size) {
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        int creds=0;
        for(auto it : boxTypes){
            if(it[0]<= size){
                creds+=it[1]*it[0];
                size-=it[0];
            }else if(size!=0){
                creds+= size*it[1];
                size=0;
            }
        }
        return creds;
    }
};