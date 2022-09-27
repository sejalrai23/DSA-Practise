class Solution {
public:
    string pushDominoes(string dom) {
        int n=dom.size();
        int right=-1;
        
        for(int i=0;i<n;i++){
            if(dom[i]=='L'){
                if(right==-1){
                    for(int j=i-1;j>=0 && dom[j]=='.';j--){
                        dom[j]='L';
                    }
                }else if(right!=-1){
                    for(int k=right+1 , j=i-1;k<j ; k++, j--){
                        dom[k]='R';
                        dom[j]='L';
                    }
                    right=-1;
                }
            }else if(dom[i]=='R'){
                if(right!=-1){
                    for(int j=right+1;j<i;j++){
                        dom[j]='R';
                    }
                }
                right=i;
            }
        }
         if(right!=-1){
             for(int j=right+1;j<n;j++){
                dom[j]='R';
            }
        }
        return dom;
    }
};