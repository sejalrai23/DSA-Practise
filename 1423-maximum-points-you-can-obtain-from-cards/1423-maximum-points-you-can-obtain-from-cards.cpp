class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int i=0 , j=0, rem=card.size()-k;
        int scr=0, mini=INT_MAX,sum=0;
        
        for(auto it:card){
            sum+=it;
        }
        
        
        while(j<card.size()){
            scr+=card[j];
            if(j-i+1<rem) j++;
            else if(j-i+1==rem){
                mini=min(scr, mini);
                j++;
            }else if(j-i+1> rem){
                while(j-i+1>rem){
                    scr-=card[i];
                    i++;
                }
                if(j-i+1==rem){
                    mini=min(scr, mini);
                }
                j++;               
            }
        }
        
        return sum-mini;
    }
};