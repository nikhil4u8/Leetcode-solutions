/*
Ques to ask :
    - Can we use a letter more than once?
    - Can we go diagonally?

Sol :
    - Firstly, we'll traverse in the whole board and finds the position 
    when first char matches.
    - Now, there is a possibility that there might exist a word which 
    matches to the given string
    - So we start to travel in all 4 direction, and use backtracking to 
    find if there exist any matching word, if these exist then return 
    true, otherwise after all iteration return false

Edge case :
    - If len of word > matrix size

Similar Ques : 
    - Find how many word from words array exist in grid?
        -> Ref. 212. Word Search II
    - Find if a word exist in grid
        -> Ref. 79. Word Search
*/
class Solution {
public:
    //TIME - O(N*3^L)->N is no of cell in board & L is len of word
    //EXPLANATION FOR TIME COMPLEXITY
    //For the backtracking function, initially we could have at most 4 directions to explore, but 
    //further the choices are reduced into 3 (since we won't go back to where we come from). As a 
    //result, the execution trace after the first step could be visualized as a 3-ary tree, each of 
    //the branches represent a potential exploration in the corresponding direction. Therefore, in 
    //the worst case, the total number of invocation would be the number of nodes in a full 3-nary 
    //tree, which is about 3^L.
    //SPACE - O(L)->RECURSIVE STACK
    class Solution {
public:
    vector<int>x0 = {1,-1,0,0};
    vector<int>y0 = {0,0,1,-1};
    bool search(vector<vector<char>>& board, string word, int i, int j, int idx, int n, int m){
        if(idx == word.length()) return true;

        for(int k=0;k<4;k++){
            int x = i + x0[k];
            int y = j + y0[k];

            if(x>=0 && y>=0 && x<n && y<m && word[idx] == board[x][y]){
                board[x][y] = '#';
                if(search(board, word, x, y, idx+1, n, m)) return true;
                board[x][y] = word[idx];
            }
        }

        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == word[0]){
                    //If first char matches then only proceed with matching
                    //of other char
                    board[i][j] = '#';
                    if(search(board, word, i, j, 1, n, m)) return true;
                    board[i][j] = word[0];
                } 
            }
        }

        return false;
    }
};

class Solution {
public:
    bool search(vector<vector<char>>&board, int i, int j, string word, int k){
        if(k == word.length()-1) return true;
                
        bool ans = false;
        char ch = board[i][j];
        
        board[i][j] = '.';
        
        k++;
        
        if(i>0 && board[i-1][j] == word[k]) ans = ans || search(board, i-1, j, word, k);
        if(j>0 && board[i][j-1] == word[k]) ans = ans || search(board, i, j-1, word, k);
        if(i<board.size()-1 && board[i+1][j] == word[k]) ans = ans || search(board, i+1, j, word, k);
        if(j<board[0].size()-1 && board[i][j+1] == word[k]) ans = ans || search(board, i, j+1, word, k);
        
        board[i][j] = ch;
        
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == word[0] && search(board, i, j, word, 0))
                    return true;
            }
        }
        
        return false;
    }
};