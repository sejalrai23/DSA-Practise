
   class Solution {
public:
    string getSmallestString(int n, int k) {
        string res="";
        for(int i=0;i<n;i++)
            res+='a';
        k=k-n;
        for(int i=n-1;i>=0;i--)
        {
            if(k==0)
                break;
            else if(k<25)
            {
                res[i] = (char)('a'+k);          
                k=0;
            }
            else{
                res[i] = (char)('a'+25);
                k = k - 25;
            }
        }
        return res;
    }
};
