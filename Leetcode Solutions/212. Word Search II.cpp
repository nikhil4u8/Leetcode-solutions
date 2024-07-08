/*
Ques to ask : 
    - Can we use a char from board multiple times in a single word or 
    multiple word?
    - What if word array is empty?

Sol : 
=> Recursive
    - For each word, we can traverse whole grid and find if that word 
    exist or not

BEST APPROACH
=> Trie : [TIME - O(MN*4*3^T) SPACE - O(k)]
-> K is sum of len of all words
-> N,M : size of our board, T : len of longest word
-> TIME explanation see below
    - Insert each word in words array in our trie
    - From each char in board do a DFS traversal, to see if the DFS 
    matches any word present in trie, if matches then add those words into 
    our ans set & return it. While searching we've to keep track of 
    already visited cells too.

Edge case : 
    - [["a","a","a"],["a","a","a"]], words = ["aaa"]

Similar Ques : 
    - Find how many word from words array exist in grid?
        -> Ref. 212. Word Search II
    - Find if a word exist in grid
        -> Ref. 79. Word Search
*/
struct Trie{
    bool isEnd;
    string word;
    unordered_map<char, Trie*>child;
};
class Solution {
public:
//BEST APPROACH
//TRIE
    Trie* root;
    unordered_set<string>ans;

    vector<int>dir_x = {0,0,1,-1};
    vector<int>dir_y = {1,-1,0,0};
    void insert(string word){
        Trie* temp = root;
        for(int i=0;i<word.length();i++){
            char x = word[i];

            if(temp->child.find(x) == temp->child.end())
                temp->child[x] = new Trie();
            temp = temp->child[x];
        }
        temp->isEnd = true;
        temp->word = word;
    }
    void search(int x, int y, int n, int m, vector<vector<char>>&board, Trie* temp){  
        if(!temp) return;
        if(temp->isEnd) ans.insert(temp->word);

        char t = board[x][y];
        board[x][y] = '#';

        for(int i=0;i<4;i++){
            int x0 = x + dir_x[i];
            int y0 = y + dir_y[i];

            if(x0 >= 0 && y0 >= 0 && x0 < n && y0 < m){
                char c = board[x0][y0];
                if(temp->child.find(c) != temp->child.end())
                    search(x0, y0, n, m, board, temp->child[c]);
            }
        }

        board[x][y] = t;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {      
        int n = board.size();
        if(n == 0) return {};
        int m = board[0].size();

        root = new Trie();
        for(int i=0;i<words.size();i++)
            insert(words[i]);
        
        Trie* temp = root;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                char x = board[i][j];
                search(i, j, n, m, board, temp->child[x]);
            }
        }

        return vector<string>(ans.begin(), ans.end());
    }
};
/*
O(NM*4*3^T) : 
Since, we've to traverse whole board so NM
Assuming max len of word = T, in worst case of 
[["a","a","a"],["a","a","a"]] when all char are equal, then initially we'd 
have at most 4 dir to explore, assuming each dir is valid (worst case), 
so during exploration we've at most 3 neighbor cells (exluding the cell 
where we come from) to explore. So we'd traverse at most 4*3^T cells 
during backtracking exploration.
*/