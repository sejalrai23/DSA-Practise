class Solution {
public:
    bool validUtf8(vector<int>& data) {
        for(int i=0;i<data.size();i++){
            int x=0,y=data[i];
            for(int j=7;j>=0;j--){
                if(!(y&(1<<j)))break;
                x++;
            }
            int t=x-1,j=i+1;
            if(x==1||x>4)return false;
            while(t>0 && j<data.size()){
               y=data[j];
               int b1=(1<<7),b2=(1<<6); 
               if(!((y&b1) && !(y&b2))){
                   return false;
               } 
               j++;t--; 
            }
            if(t>0)return false;
            i=j-1;
        }
        return true;
    }
};