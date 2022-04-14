class Solution {
public:
    bool isValid(int mid, int m ,vector<int>& position  ){
        int p=1;
        int prev=position[0];
        for(int i=1;i<position.size();i++){
            if(position[i]-prev>=mid){
                prev=position[i];
                p++;
                if(p==m) return true;
            }
            
        }
        if(p<m) return false;
        return true;
    }
    int maxDistance(vector<int>& position, int m) {
        int n=position.size();
        sort(position.begin(),position.end());
        int st=1, end=position[n-1]-position[0];
        int ans;
        while(st<=end){
            int mid= st + (end-st)/2 ;
            if(isValid(mid , m , position)){
                ans=mid ;
                st=mid+1;
            }else{
                end=mid-1;
            }
        }
        return ans;
        
        
    }
};