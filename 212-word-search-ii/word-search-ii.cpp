class trie {
    public:
    trie *arr[26];
    bool end = false; // if a word ends here or not since there can be prefixes as well
    string s = ""; // to keep track of how far down we have traversed
    trie() {
        memset(arr, 0, sizeof(arr));
    }
};
class Trie {
    public:
    trie *root;
    Trie() {
        root = new trie();
    }
    void insert(string &word)
    {
        int n = word.size();
        trie *temp = root;
        for(int i=0; i<n; i++)
        {
            if(temp->arr[word[i]-'a'] == NULL)
            {
                temp->arr[word[i]-'a'] = new trie();
            }
            temp = temp->arr[word[i]-'a'];
        }
        temp->end = true;
		// making use of string only here since we don't need it otherwise
        temp->s = word;
    }
};
class Solution {
public:
	// we can move in all 4 directions in very less line(s) of code using this
    vector<vector<int>> moves{{0,0,-1,1}, {1,-1,0,0}};
	
	//our final ans
    vector<string> ans;
	
	//main function
    void dfs(vector<vector<char>>& board, vector<string>& s, trie* ptr, int i, int j)
    {
        if(i==-1 || i==board.size() || j==-1 || j==board[0].size() || board[i][j]=='#') return;
        
		//traversing towards the character board[i][j] of the string (if present)
		//this will be the first character of string when executed the first time (from the main original function)
        ptr = ptr->arr[board[i][j]-'a'];
        
		//if no such word exist then we simply return
        if(!ptr) return;
		
		//if this is a end that means a word exists so we append it to our ans
        if(ptr->end) 
        {
            ptr->end = false;
            ans.push_back(ptr->s);
        }
		
		//since we can't come to a cell once traversed 
        char el = board[i][j];
		// we make it unusable for mean time
        board[i][j] = '#';
		
		//traversing in all 4 directions with a single line of code !!
        for(int x=0; x<4; x++) dfs(board, s, ptr, i+moves[0][x], j+moves[1][x]);
		
		//backtracking
        board[i][j] = el;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& s) {
        int n = board.size(), m = board[0].size(), ss = s.size();
        Trie obj;
		//building the trie
        for(int k=0; k<ss; k++)
        {
            obj.insert(s[k]);
        }
		//instead of traversing for all words we just traverse one time across the whole board
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                dfs(board, s, obj.root, i, j);
            }
        }
        return ans;
    }
};