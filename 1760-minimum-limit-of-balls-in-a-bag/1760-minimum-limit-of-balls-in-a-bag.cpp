class Solution {
public:
    int minimumSize(vector<int>& nums, int maxi) {
        int st=1, end= *max_element(nums.begin(),nums.end());
        int minPen=end;
        while(st<=end){
            int p= st+(end-st)/2;
            if(maxOps(nums,maxi,p)){
                minPen=p;
                end=p-1;
            }else{
                st=p+1;
            }
            
        }
        return minPen;
        
    }
    
    bool maxOps(vector<int>& nums , int maxi , int pen){
        int req=0;
        for(auto i:nums){
            int x= i/pen;
            if(i%pen==0){
                x--;
            }
            req+=x;
        }
        return req<=maxi;
    }
};