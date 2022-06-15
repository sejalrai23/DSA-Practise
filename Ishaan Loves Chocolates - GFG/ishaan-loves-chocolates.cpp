// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


int chocolates(int arr[], int n);


int main()
{
    
    int t;cin>> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        
        cout << chocolates(arr, n);
        cout << endl;
        
    }

}
// } Driver Code Ends


int chocolates(int arr[], int n)
{
    // Complete the function
    int sum=0;
    for(int i=0;i<n ;i++){
        sum+=arr[i];
    }
    
    int i=0 , j=n-1;
    while(i<j){
        if(arr[i]> arr[j]){
            sum-=arr[i];
            i++;
        }else{
            sum-=arr[j];
            j--;
            
        }
    }
    return sum;
    
}
