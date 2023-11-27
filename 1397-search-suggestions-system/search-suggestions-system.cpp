class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        set<string>s;
        vector<vector<string>>res;
        for(int i = 0 ; i < products.size() ; i++){
            s.insert(products[i]);
        }
        for(int i = 1 ; i <= searchWord.size() ; i++){
           set<string>s1 = s;
           vector<string>ans;

           string prefix = searchWord.substr(0,i);

           for(string element : s1){
               if(element.substr(0,i) == prefix){
                   ans.push_back(element);
               }
           }
           if(ans.size() > 3)
           res.push_back({ans[0], ans[1], ans[2]});

           else
           res.push_back({ans});

        }
    return res;
    }
};