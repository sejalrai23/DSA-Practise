class Solution {
public:
    
    int returnMax(string s, char h, int k){
         int i=0, j=0;
        int cnt=0,mx=0;
        // cout<<h<<endl;
        while(j<s.length()){
            if(s[j]==h){
                cnt++;
            }
            if(cnt<=k){
                mx=max(mx, j-i+1);
                j++;
            }else if(cnt>k){
                while(cnt>k){
                    if(s[i]==h){
                        cnt--;
                    }
                    i++;
                }
                j++;    
            }  
          
        }
         return mx;
    }
       
    
    int maxConsecutiveAnswers(string answerKey, int k) {
        char charF='F', charT='T';
        int mxF=returnMax(answerKey, charF, k);
        int mxT= returnMax(answerKey, charT,k);
        return max(mxF, mxT);
        
    }
};
