/*
Ques to ask :
    - Can we've empty string as a word?

Sol :
=> Brute Force : [TIME - O(1) O(1) (N*L) SPACE - O(N*L)]
-> L is len of longest word
    - store all word in vector & while searching for a word match it with 
    every word in vector, if it matches with any word then return true,
    else false

BEST APPROACH
=> Using Trie : [TIME - O(1) O(L) O(N*L) SPACE - O(N*L)] 
-> L -> len of a word
    - use trie to store words 
    - While searching a word when a '.' is found, then traverse all the 
    children of the current node and recursively search the remaining 
    substring starting from each of those children.

Follow up :
    - how to handle "*" in search pattern with trie tree?
*/
//TIME - O(1) O(L) O(N*L) SPACE - O(N*L)
//Worst case time is O(N*L), if string is "...."
struct Trie{
    bool isEnd = false;
    unordered_map<char, Trie*>child;
};
class WordDictionary {
public:
    Trie* root;
    WordDictionary() {
        root = new Trie();
    }
    
    void addWord(string word) {
        Trie* temp = root;
        for(int i=0;i<word.length();i++){
            char x = word[i];

            if(temp->child.find(x) == temp->child.end())
                temp->child[x] = new Trie();

            temp = temp->child[x];
        }
        temp->isEnd = true;
    }
    
    bool search(string word, Trie* currRoot = NULL) {
        Trie* temp = currRoot;
        if(!currRoot) temp = root;
        
        for(int i=0;i<word.length();i++){
            char x = word[i];

            //if '.' is found, then skip that char & move to child node
            if(x == '.'){
                string substr = word.substr(i+1);
                for(auto it : temp->child){
                    if(search(substr, it.second)) return true;
                }
                return false;
            }

            if(temp->child.find(x) == temp->child.end())
                return false;
            temp = temp->child[x];
        }

        return temp->isEnd;
    }
};