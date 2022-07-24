class Solution {
public:

      int clumsy(int N){
    int rem[4] = {1, 2, 2, -1}; 
    if (N < 3) return N;
      if (N < 5) return N+3;
      return N + rem[N%4];
    }
};