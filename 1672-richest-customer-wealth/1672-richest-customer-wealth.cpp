class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max1=0;
        for(auto it: accounts){
            int sum=0;
            for(int i=0; i<it.size();i++){
                sum+=it[i];
            }
            max1=max(sum, max1);
        }
        return max1;
        
    }
};