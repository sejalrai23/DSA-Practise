class Solution {
public:
    int minDeletions(string s) {
       vector<int> vec(26);
        for(auto it:s){
            vec[it-'a']++;
        }
        sort(vec.begin(),vec.end(), greater<int>());
        int prev=vec[0]+1;
        int ans=0;
        
        for(int i=0;i<vec.size();i++){
            cout<<vec[i]<<endl;
            while(vec[i]>=prev && prev>0){
                vec[i]--;
                ans++;
            }
            if(prev==0){
                ans+=vec[i];
                vec[i]=0;
            }
            prev=vec[i];
        }
        

        
        return ans;
    }
};