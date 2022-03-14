class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        string final="";
        size_t pos_start = 0, pos_end;
        string token;
        vector<string> res;

       while ((pos_end = path.find ("/", pos_start)) !=  string::npos) {
        token = path.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + 1;
        res.push_back (token);
       }
 
      res.push_back (path.substr (pos_start));
        // s.push("/");
        
       // for (auto i : res) {cout << i << endl;}
        for(int i=0;i<res.size();i++){
            if (res[i]!="." && !res[i].empty()) {
			if (res[i]=="..") {
				if (!s.empty())
					s.pop();
			} else
				s.push(res[i]);
		}
        }
        
      while(!s.empty())
        {
          if(s.top()==""){
               s.pop();
              continue;
          }else{
           final = '/' + s.top() + final;
            s.pop();
          }
          
         
          
        }
        
        
    return final.empty()? "/" : final;
    }
};