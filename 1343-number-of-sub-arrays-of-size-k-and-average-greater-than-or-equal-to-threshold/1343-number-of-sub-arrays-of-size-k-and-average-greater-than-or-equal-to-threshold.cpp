class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int i=0, j=0;
        int avg=0,cnt=0;
        while(j<arr.size()){
             avg+=arr[j];
            if(j-i+1<k){
                j++;
            }else if(j-i+1==k){
                if(avg>=threshold*k){
                    cnt++;
                }
                avg-=arr[i];
                i++;
                j++;
            }
        }
        return cnt;
    }
};