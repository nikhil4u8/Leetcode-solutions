struct Trie{
    unordered_map<char,Trie*>child;
    bool isend = false;
};
class MagicDictionary {
public:
    Trie* root;
    
    MagicDictionary() {
        root = new Trie();
    }
    void insert(string str){
        Trie* temp = root;
        
        for(int i=0;i<str.length();i++){
            char x = str[i];
            
            if(temp->child.find(x) == temp->child.end())
                temp->child[x] = new Trie();
            temp = temp->child[x];
        }
        temp->isend = true;
    }
    void buildDict(vector<string> dictionary) {
        for(int i=0;i<dictionary.size();i++){
            insert(dictionary[i]);
        }
    }
    
    bool solve(string str, Trie* temp, int index, int count = 0){
        if(index == str.length() && temp->isend) return count != 0;
        
        if(count != 0){
            if(temp->child.find(str[index]) == temp->child.end()) return false;
            temp = temp->child[str[index]];
            return solve(str,temp,index+1,count);
        }
        
        bool ans = false;
        for(auto it : temp->child){
            if(it.first != str[index] && solve(str,it.second,index+1,count+1))
                return true;
            if(it.first == str[index] && solve(str,it.second,index+1,count))
                return true;
        }
        
        return false;
    }
    bool search(string searchWord) {
        return solve(searchWord,root,0,0);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */