// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    
    double solve(double l , double h , double magnets[], int n){
        double mid;
        while(l<h){
            mid=l+ (h-l)/2;
            double force=0;
            for(int i=0;i<n ; i++){
                force+= 1 / (mid-magnets[i]);
            }
            // cout<<force<<"----"<<mid<<endl;
            if(abs(force)<0.0000001) return mid;
            else if(force<0){
                h=mid;
            }else{
                l=mid;
            }
        }
        return mid;
    }
        void nullPoints(int n, double magnets[], double getAnswer[])
    {
        // Your code goes here   
        for(int i=0; i<n-1;i++){
            getAnswer[i]=solve(magnets[i], magnets[i+1], magnets, n);
        }
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        double magnets[n], getAnswer[n];
        for(int i=0;i<n;i++)
        cin>>magnets[i];
        Solution ob;
        ob.nullPoints(n, magnets, getAnswer);
        
        for(int i=0; i<n-1; i++)
            printf("%0.2lf ",getAnswer[i]);
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends