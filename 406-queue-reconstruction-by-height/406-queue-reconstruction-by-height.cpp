class Solution {
public:
    static bool cmp(vector<int> & a , vector<int>& b){
        if(a[0]==b[0]){
            return a[1]<b[1];
        }
        return a[0]<b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),cmp);
        vector<vector<int>> ans(people.size(), {-1,-1});
        for(auto it : people){
            cout<<it[0]<<"-"<<it[1]<<endl;
            int idx= it[1];
            for(int i=0;i<people.size();i++){
                if(ans[i][0]== -1 && idx==0){
                    ans[i][0]=it[0];
                    ans[i][1]=it[1];
                    break;
                }else if(ans[i][0]== -1 || ans[i][0] >=it[0]){  //decrease idx only when the gap is empty or it is filled with some other person with greater than or euql height
                    idx--;
                }
            }
        }
        return ans;
       
    }
};