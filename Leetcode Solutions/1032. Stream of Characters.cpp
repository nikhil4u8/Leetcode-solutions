struct Trie{
    unordered_map<char,Trie*>child;
    bool isend = false;
};
class StreamChecker {
public:
    Trie* root;
    string cache;
    int longest_word;
    void insert_word(string str){
        Trie* temp = root;
        
        for(int i=str.length()-1;i>=0;i--){
            char x = str[i];

            if(temp->child.find(x) == temp->child.end())
                temp->child[x] = new Trie();
            temp = temp->child[x];
        }
        temp->isend = true;
    }
    
    bool find_suffix(string str){
        Trie* temp = root;
        
        for(int i=str.length()-1;i>=0;i--){
            char x = str[i];
            
            if(temp->child.find(x) == temp->child.end())
                return false;
            temp = temp->child[x];
            
            if(temp->isend) return true;
        }
        
        return temp->isend;
    }
    StreamChecker(vector<string>& words) {
        root = new Trie();
        cache = "";
        
        for(int i=0;i<words.size();i++){
            insert_word(words[i]);
            longest_word = max(longest_word, (int)words[i].length());
        }
    }

    bool query(char letter) {
        cache += letter;
        bool ans = find_suffix(cache);
        if(cache.length() > longest_word) 
            cache = cache.substr(cache.length() - longest_word + 1);
        return ans;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */