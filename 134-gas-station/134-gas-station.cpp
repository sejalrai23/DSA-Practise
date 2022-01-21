class Solution {
public:
    bool canDo(int i ,int j, vector<int>& gas , vector<int>& cost,int rem){
        while(j!=i){
            if(j<gas.size()){
                if(rem +gas[j]-cost[j]<0){
                    return false;
                }else{
                    rem+=gas[j]-cost[j];
                    j++;
                }
            }else{
                j=0;
            }
            
        }
        return true;
        
        
    }
    
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int len=gas.size();
        if(len==1){
            if(gas[0]-cost[0]>=0){
                return 0;
            }
            else{
                return -1;
            }
        }
        
        for(int i=0; i <len ;i++){
            if(gas[i]-cost[i]>0){
                int rem=gas[i]-cost[i];
                if(canDo(i,i+1,gas, cost,rem)){
                    return i;
                }
            }
        }
        return -1;
        
    }
};