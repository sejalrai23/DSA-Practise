class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        int ans=0;
        for(auto it : m){
            int req= it.first - k;
            if(m.find(req)!=m.end()){
                if(req==it.first){
                    ans+= it.second >1 ? 1 :0;
                }else{
                    ans++;
                }
            }
        }
        return ans;
        
    }
};