class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int maxi=0,i=0,j=0,st=0, end=0,sum=0;
        unordered_map<int,int> ump;
        while(j<nums.size()){
            ump[nums[j]]++;
            // sum+=nums[j];
            if(j-i+1<ump.size()){
                j++;
            }else if(j-i+1==ump.size()){
                int sum1=0;
                for(int s=i;s<=j;s++){
                    sum1+=nums[s];
                }
                sum=max(sum1,sum);
                j++;
            }else if(j-i+1>ump.size()){
                while(j-i+1>ump.size()){
                    ump[nums[i]]--;
                    if(ump[nums[i]]==0){
                        ump.erase(nums[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        // for(int s=st;s<=end;s++){
        //     sum+=nums[s];
        // }
        // cout<<st<<"-"<<end<<endl;
        return sum;
        
    }
};