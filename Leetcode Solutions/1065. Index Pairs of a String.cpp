struct Trie{
    unordered_map<char, Trie*>child;
    bool isend = false;
};
class Solution {
public:
    Trie* root;
    vector<vector<int>>res;
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
    void search(string str, int index){
        Trie* temp = root;
        
        for(int i=index;i<str.length();i++){
            char x = str[i];
            
            if(temp->child.find(x) == temp->child.end()) return;
            
            temp = temp->child[x];
            if(temp->isend) res.push_back({index, i});
        }
    }
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        root = new Trie();
        for(int i=0;i<words.size();i++) insert(words[i]);
        
        
        for(int i=0;i<text.length();i++)
            search(text, i);
        
        
        sort(res.begin(), res.end());
        return res;
    }
};