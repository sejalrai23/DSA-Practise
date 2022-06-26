class Solution {
public:
 int dp1[1005][1005][4];
 int dp2[1005][1005][4];
    int inc(int &n,int ind,int val,int k,vector<int> &rating){
        if(k==3) return 1;
        if(ind>=rating.size()) return 0;
        if(dp1[ind][val][k]!=-1) return dp1[ind][val][k];
        int take=0;
       if(val==n or rating[val]<rating[ind])
            take=inc(n,ind+1,ind,k+1,rating);
        
        int notTake=inc(n,ind+1,val,k,rating);
        
        return dp1[ind][val][k]=take+notTake;
    }
    
    int dec(int &n,int ind,int val,int k,vector<int> &rating){
        if(k==3) return 1;
        if(ind>=rating.size()) return 0;
        if(dp2[ind][val][k]!=-1) return dp2[ind][val][k];
        int take=0;
       if(val==n or rating[val]>rating[ind])
            take=dec(n,ind+1,ind,k+1,rating);
        
        int notTake=dec(n,ind+1,val,k,rating);
        
        return dp2[ind][val][k]=take+notTake;
    }
    
    int numTeams(vector<int>& rating) {

        int n=rating.size();
        memset(dp1,-1,sizeof(dp1));
        memset(dp2,-1,sizeof(dp2));
        //vector<vector<vector<int>>> dp1(n+1, vector<vector<int>>(n+3, vector<int>(3,-1)));
       // vector<vector<vector<int>>> dp2(n+1, vector<vector<int>>(n+3, vector<int>(3,-1)));
      return dec(n,0,n,0,rating)+inc(n,0,n,0,rating);
    }
};