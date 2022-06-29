class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        // if(label==1) return {1};
        vector<int> ans;
        int idx=0, sum=0;
        while(sum<label){
            sum+=pow(2,idx);
            idx++;    
        }
        idx--;
       
        int pos;
        if(idx%2==0){
            pos = pow(2,idx)-(sum-label);
        }else{
           pos=sum-label+1; 
        } 
        cout<<idx<<"-"<<sum<<"-"<<pos<<endl;
        ans.push_back(label);
        while(idx>=1){
            int parpos= (pos+1)/2;
             idx--;
            if(idx%2==0){
                label=pow(2, idx)+parpos-1;
                pos=parpos;
            }else{
               label=pow(2,idx)+ (pow(2,idx) -parpos);
                pos=parpos;
            }
            ans.push_back(label);
           
        }
        
        // cout<<label<<"-"<<pos<<endl;
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
}; 