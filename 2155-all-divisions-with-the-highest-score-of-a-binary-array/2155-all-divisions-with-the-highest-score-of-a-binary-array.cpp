class Solution {
public:
    void buildRecur(int i, map<int,vector<int>>& v , vector<int>& nums,int& sum){
        if(i>nums.size()-1){
            return;
        }
        nums[i]== 0 ? sum++ : sum--;
      
        v[sum].push_back(i+1);
     
        // cout<<sum<<endl;
        
        buildRecur(i+1,v,nums, sum);
      
    
    }
    
    
    vector<int> maxScoreIndices(vector<int>& nums) {
        map<int,vector<int> >v;
        int sum=0;
        for(int i=0; i<nums.size();i++){
            if(nums[i]==1){
                sum++;
            }
        }
        v[sum].push_back(0);
        buildRecur(0,v,nums,sum);
        auto it= v.rbegin();
        return it->second;
        
    }
};