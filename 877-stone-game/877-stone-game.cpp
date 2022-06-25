class Solution {
public:
    bool stoneGame(vector<int>& a) {
        int alice=0 , bob=0;
        int i=0, j=a.size()-1;
        int c=0;
        while(i<=j){
            if(c%2==0){
               if(a[i]>a[j]){
                   alice+=a[i];
                   i++;
               }else{
                   alice+=a[j];
                   j--;
               }
               c++;
            }else{
                if(a[i]>a[j]){
                   bob+=a[j];
                   j--;
               }else{
                   bob+=a[i];
                   i++;
               }
               c++;
                
            }
            
        }
        
        return alice>bob;
    }
};