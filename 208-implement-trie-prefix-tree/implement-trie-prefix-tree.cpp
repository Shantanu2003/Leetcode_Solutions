class Trie {
public:
    set<string>s;
    stack<string>st;
    stack<string>st1;

    Trie() {
        
    }
    
    void insert(string word) {
        s.insert(word);
        st.push(word);
    }
    
    bool search(string word) {
        if(s.find(word) != s.end())
        return true;

        else
        return false;
    }
    
    bool startsWith(string prefix) {
        if(st.size()==0){
            return false;
        }
        st1 = st;
        int size = prefix.size();

        while(!st1.empty()){
            
        string prev = st1.top();

        if(prev.substr(0,size) == prefix){
        return true;
        break;
        }

        st1.pop();
        
      }
    return false;

    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */