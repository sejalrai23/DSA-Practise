#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    while(n--){
        int k;
        cin>>k;
        int a[k];
        for(int i=0;i<k;i++){
            cin>>a[i];
        }
        for(int i=0 ; i<k/2;i++){
            swap(a[i],a[k-1-i]);
            
        }
        for(int i=0;i<k;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
	//code
	return 0;
}