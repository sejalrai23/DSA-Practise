class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1,v2;
        stringstream ss(version1);
        string s;
        while (std::getline(ss, s, '.')) {
            v1.push_back(stoi(s));
        }
        stringstream sss(version2);
        while (std::getline(sss, s, '.')) {
           v2.push_back(stoi(s));
        }
        // for(auto it:v2){cout<<it<<endl;}
        if(v1.size()>v2.size()){
            for(int i=0;i<=v1.size()-v2.size();i++){
                v2.push_back(0);
            }
        }
        else if(v2.size()>v1.size()){
            for(int i=0;i<=v2.size()-v1.size();i++){
                v1.push_back(0);
            }
        }
        for(int i=0;i<min(v1.size(),v2.size());i++){
            if(v1[i]>v2[i]){
                return 1;
            }
            else if(v1[i]<v2[i]){
                return -1;
            }
        }
        return 0;
    }
};