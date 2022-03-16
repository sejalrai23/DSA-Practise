//sieve of eratosthenes
class Solution {
public:
    int countPrimes(int n) {
        if(n==0){
            return 0;
        }
        int cnt=0;
        bool prime[n];
        memset(prime ,true , sizeof(prime));
        for(int i=2;i*i<n;i++){
            if(prime[i]==true){
                for(int j=i*i ;j<n ;j+=i){
                    prime[j]=false;
                }
            }
        }
        for(int i=2;i<n;i++){
            if(prime[i]){
                cnt++;
            }
        }
        return cnt;
    }
};