class Solution {
public:

    int cnt=0;
    void Combi(int idx ,int n,int pos){
        if(idx==n){
            cnt++;
            return;
        }
        for(int i=pos;i<5;i++){
            Combi(idx+1,n,i);
        }
    }
    int countVowelStrings(int n) {
        Combi(0,n,0);
        return cnt;
    }
};