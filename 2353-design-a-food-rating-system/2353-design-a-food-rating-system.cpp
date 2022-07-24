class FoodRatings {
public:
    struct comp{
    bool operator() (pair<int,string> &a,pair<int,string> &b){
        if(a.first==b.first) return a.second>b.second;
        return a.first<b.first;
    }
};
    
    map<string ,priority_queue<pair<int,string>,vector<pair<int,string>>,comp> > mp;
    map<string , string> foodCus;
    map<string,int> rat;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n=foods.size();
         for(int i=0;i<n ;i++){
             mp[cuisines[i]].push({ratings[i], foods[i]});
             foodCus[foods[i]]=cuisines[i];
             rat[foods[i]]=ratings[i];
         }
        
      
        
    }
    
    void changeRating(string food, int newRating) {
        rat[food]=newRating;
        string cuss= foodCus[food];
        mp[cuss].push({newRating, food});
        
    }
    
    string highestRated(string cuisine) {
        int maxi=mp[cuisine].top().first;
        string f= mp[cuisine].top().second;
        while(rat[f]!=maxi ){
            mp[cuisine].pop();
            f= mp[cuisine].top().second;
            maxi=mp[cuisine].top().first;
            
        }
        
        return mp[cuisine].top().second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */