class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string>source;
        unordered_set<string>destination;

        for(int i = 0 ; i < paths.size() ; i++){
           source.insert(paths[i][0]);
           destination.insert(paths[i][1]);
        }
        
        for(auto i: destination){
            if(source.find(i) == source.end()){
                return i;
            }
        }
        return "";
    }
};