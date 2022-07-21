class Solution {
public:
    int numTilePossibilities(string tiles) {   
        set<string> answer;   
       vector<int> vis(tiles.length(),0);
        string path = ""; 
        backtrack(tiles, answer, path, vis); 
        return answer.size()-1;
    } 
    
    void backtrack(string tiles, set<string> &answer, string path, vector<int> &visited) {  
        answer.insert(path); 
        for(int i = 0; i < tiles.length(); i++) { 
            if (visited[i] == true) { 
                continue;
            } 
            path.push_back(tiles[i]); 
            visited[i] = true; 
            backtrack(tiles, answer, path, visited); 
            visited[i] = false; 
            path.pop_back();
        }
    }
};