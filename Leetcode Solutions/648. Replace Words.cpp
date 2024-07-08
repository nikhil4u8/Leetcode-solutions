struct Trie{
    unordered_map<char, Trie*>child;
    bool isend = false;
};
class Solution {
public:
    Trie* root;
    void insert(string word){
        Trie* temp = root;
        
        for(int i=0;i<word.length();i++){
            char x = word[i];
            
            if(temp->child.find(x) == temp->child.end())
                temp->child[x] = new Trie();
            
            temp = temp->child[x];
        }
        temp->isend = true;
    }
    string search(string word){
        Trie* temp = root;
        
        for(int i=0;i<word.length();i++){
            char x = word[i];
            
            if(temp->child.find(x) == temp->child.end())
                return word;
            
            temp = temp->child[x];
            if(temp->isend) return word.substr(0, i+1);
        }
        return word;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        root = new Trie();
        for(int i=0;i<dictionary.size();i++) insert(dictionary[i]);
        
        string res = "", temp_str = "";
        for(int i=0;i<sentence.length();i++){
            if(sentence[i] == ' '){
                res += search(temp_str) + " ";
                temp_str = "";
            }else temp_str += sentence[i];
        }
        
        if(temp_str != "") res += search(temp_str);
        
        return res;
    }
};