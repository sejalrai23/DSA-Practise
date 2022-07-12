class Solution {
public:
    
    bool dfs(vector<int> & match , int ind , int &a, int& b , int& c , int& d){
        if(ind==match.size()){
            if(a==0 && b ==0 && c==0 && d==0) return true;
            else return false;
        }
        
        if(match[ind]<=a){
            a-=match[ind];
            if(dfs(match , ind+1, a, b , c ,d)) return true;
            a+=match[ind];
        }
        
        if(match[ind]<=b){
            b-=match[ind];
            if(dfs(match , ind+1, a, b , c ,d)) return true;
            b+=match[ind];
        }
        if(match[ind]<=c){
            c-=match[ind];
            if(dfs(match , ind+1, a, b , c ,d)) return true;
            c+=match[ind];
        }
        if(match[ind]<=d){
            d-=match[ind];
            if(dfs(match , ind+1, a, b , c ,d)) return true;
            d+=match[ind];
        }
        
        return false;
    }
    bool makesquare(vector<int>& match) {
        int tar=0;
        if(match.size()<4) return false;
        for(auto it : match){
            tar+=it;
        }
        if(tar % 4 != 0) return false;
        tar/=4;
        int a=tar , b =tar, c=tar, d=tar;
        sort(match.rbegin(), match.rend());
        return dfs(match ,0,a, b, c ,d);
    }
};