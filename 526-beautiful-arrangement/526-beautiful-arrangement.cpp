class Solution {
public:
    int permute(vector <int> v, int idx){
	   if(idx==v.size()+1){
		  return 1;
	   }
        int ans=0;
	   for(int i=idx-1;i<v.size();i++){
		  if(v[i]%(idx)==0 || (idx)%v[i]==0){
			swap(v[i], v[idx-1]);
			ans+=permute(v, idx+1);
			swap(v[i], v[idx-1]);
		 }
	   }
      return ans;
     }
    
    int countArrangement(int N) {
	    vector <int> v;

	    for(int i=1; i <= N; i++){
		    v.push_back(i);
	    }
	   
	   return permute(v, 1);
}
};