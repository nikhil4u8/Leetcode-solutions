struct Trie{
    unordered_map<string, Trie*>child;
    bool isend = false;
    Trie* parent = NULL;
    int len = 0;
};
class Solution {
public:
    Trie* root;
    int max_len = 0;
    void insert(string input){
        Trie* temp = root;
        
        int count = 0, prev_count=0, index=0;
        string dir = "";
        
        while(index<input.length()){
            char x = input[index];
            
            if(x == '\n') index++;
            else if(x == '\t') count++;
            else{
                if(count > prev_count) temp = temp->child[dir];
                else{
                    while(temp->parent && count != prev_count){
                        temp = temp->parent;
                        prev_count--;
                    }
                }
                
                dir = "";
                bool isfile = false;
                
                while(index<input.length() && input[index] != '\n'){
                    if(input[index] == '.') isfile = true;
                    dir += input[index++];
                }
                
                if(temp->child.find(dir) == temp->child.end()){
                    temp->child[dir] = new Trie();
                    temp->child[dir]->parent = temp;
                    temp->child[dir]->len = temp->len + dir.length() + 1;
                }
                
                if(isfile){
                    temp->child[dir]->isend = true;
                    max_len = max(max_len, temp->child[dir]->len);
                }
                
                prev_count = count;
                count = 0;
            }
            
            index++;
        }
    }
    int lengthLongestPath(string input) {
        root = new Trie();
        insert(input);
        
        if(max_len == 0) return 0;
        
        return max_len - 1;
    }
};