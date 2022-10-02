class Solution {
public:
    pair<int, int> getRange(vector<int> vec){
        int end=0 , currMax=vec[0] , globalMax=vec[0];
        
        for(int i=1;i< vec.size();i++){
            currMax= max(vec[i] , vec[i]+currMax);
            if(currMax> globalMax){
                globalMax= currMax;
                end=i;
            }
            
        }
        int st= end;
        
        while(st>=0){
            globalMax-=vec[st];
            if(globalMax==0){
                break;
            }
            st--;
        }
        return {st , end};
    }
    
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<int> ans1(n , 0);
        vector<int> ans2(n , 0);
        int sum1=0 , sum2=0;
        for(int i=0;i<n ;i++){
            sum1+=nums1[i];
            sum2+=nums2[i];
            ans1[i]= nums1[i]-nums2[i];
            ans2[i]= nums2[i]-nums1[i];
        }
        
        pair<int, int> a= getRange(ans1);
        pair<int , int> b= getRange(ans2);
        
        // cout<<a.first<<"-"<<a.second<<endl;
        // cout<<b.first<<"-"<<b.second<<endl;
        for(int i= a.first;i<=a.second;i++ ){
            sum2+= nums1[i]- nums2[i];
        }
        for(int i= b.first;i<=b.second;i++ ){
            sum1+= nums2[i]- nums1[i];
        }
        return max(sum1 , sum2);
        
    }
};