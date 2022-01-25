class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size()<3){
            return false;
        }
        int i=0, max1=0, min1=0;
        int min= arr[i];
        i++;
        while(min<arr[i] && i<arr.size()){
            // cout<<min<<"-"<<arr[i]<<endl;
            min=arr[i];
            i==arr.size()-1 ? i :i++;  
            max1++;
           
        }
        int max=min;
        
        while(max>arr[i] && i<arr.size()){
            // cout<<max<<"-"<<arr[i]<<endl;
            max=arr[i];
            i==arr.size()-1 ? i :i++;  
            min1++;
        }
        // cout<<max1<<","<<min1<<endl;
        return (max1+min1==arr.size()-1 && min1!=0 && max1!=0);
        
        
    }
};