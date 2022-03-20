class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        map<int,vector<int>> m1;
        map<int,vector<int>> m2;
        for(int i=0;i<tops.size();i++){
            m1[tops[i]].push_back(i);
            m2[bottoms[i]].push_back(i);
        }
        int size1=0, key1=0;
        int size2=0 , key2=0;
        for(auto it :m1){
            // cout<<it.first<<"-"<<it.second.size()<<endl;
            int temp=it.second.size();
            if(temp>size1){
                size1=max(temp,size1);
                key1=it.first;
            }
        }
        for(auto it :m2){
            int temp=it.second.size();
            if(temp>size2){
                size2=max(temp,size2);
                key2=it.first;
            }
        }
        // cout<<key1<<"-"<<size1<<endl;
        // cout<<key2<<"-"<<size2<<endl;
        int cnt=0;
        if(size1>size2){
            vector<int> vis(tops.size(),0);
            for(auto it: m1[key1]){

                vis[it]=1;
            }
            for(int i=0;i<vis.size();i++){
                // cout<<it<<endl;
                if(vis[i]==0){
                    if(find(m2[key1].begin(),m2[key1].end(),i)!=m2[key1].end()){
                        cnt++;
                    }else{
                        return -1;
                    }
                }
            }
            vis.clear();
    
        }
        else{
            vector<int> vis(bottoms.size(),0);
            for(auto it: m2[key2]){
                vis[it]=1;
            }
            for(int i=0;i<vis.size();i++){
                if(vis[i]==0){
                    if(find(m1[key2].begin(),m1[key2].end(),i)!=m1[key2].end()){
                       cnt++;
                    }else{

                        return -1;
                    }
                }
            }
            vis.clear();

        }
        return cnt ;
        
        
        
    }
};