class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long ans=0, i=0;
        while(ans < neededApples){ 
            i++;
            ans += 12*pow(i,2);  
        }
        
        return 8*i;
    }
};