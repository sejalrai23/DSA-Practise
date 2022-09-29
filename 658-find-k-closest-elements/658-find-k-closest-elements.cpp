class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {        
        int n = size(arr), R = lower_bound(begin(arr), end(arr), x) - begin(arr), L = R - 1;
        cout<<R<<endl;
        while(k--) {
           if(R >= n || L >= 0 && x - arr[L] <= arr[R] - x) {
                  // cout<<"L"<<"-"<<L<<endl;
                   L--; 
           }
           else{
                // cout<<"R"<<"-"<<R<<endl;
               R++;
           }  
        }
        cout<<L<<"-"<<R<<endl;                                              
        return vector<int>(begin(arr) + L + 1, begin(arr) + R);
    }
};