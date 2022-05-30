class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int cnt=0, i=0, j=0, mini=INT_MAX;
        unordered_map<int,int> umap;
        while(j<cards.size()){
            umap[cards[j]]++;
            if(j-i+1==umap.size()){
                j++;
            }
            else if(j-i+1>umap.size()){
                while(j-i+1>umap.size()){
                    umap[cards[i]]--;
                    if(umap[cards[i]]==0){
                        umap.erase(cards[i]);
                    }
                    mini=min(mini,j-i+1);
                    i++;
                 
                   
                }
               
               
                j++;
            }
        }
        return mini==INT_MAX ? -1 : mini;
        
    }
};