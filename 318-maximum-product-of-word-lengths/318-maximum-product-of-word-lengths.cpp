class Solution {
public:
    int maxProduct(vector<string>& words) {
        int mx=0;
        for(int i=0;i<words.size();i++){
            unordered_map<char,int> umap;
            for(auto x:words[i]){
                umap[x]++;
            }
            for(int j=i+1; j<words.size();j++){
                int flag=0;
                for(auto x:words[j]){
                    if(umap[x]!=0){
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    int ans=words[i].length()*words[j].length();
                    mx=max(mx,ans);
                }
            }
        }
        return mx;
        
    }
};