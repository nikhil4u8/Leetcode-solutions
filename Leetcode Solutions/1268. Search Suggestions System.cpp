//4:45
struct Trie{
    unordered_map<char, Trie*>child;
    bool isend = false;
    vector<string>list;
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
            if(temp->list.size() < 3) temp->list.push_back(word);
        }
        temp->isend = true;
    }
    vector<vector<string>> search(string word){
        vector<vector<string>>ans;
        
        Trie* temp = root;
        
        for(int i=0;i<word.length();i++){
            char x = word[i];
            
            if(temp->child.find(x) == temp->child.end())
                temp->child[x] = new Trie();
    
            temp = temp->child[x];
            ans.push_back(temp->list);
        }
       
        return ans;
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        root = new Trie();
        
        sort(products.begin(), products.end());
        for(int i=0;i<products.size();i++)
            insert(products[i]);
        
        return search(searchWord);
    }
};